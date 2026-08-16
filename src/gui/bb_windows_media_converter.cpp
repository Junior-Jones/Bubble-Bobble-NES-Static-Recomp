#define UNICODE
#define _UNICODE
#include "bb_windows_media_converter.h"
#include "bb_audio_replacement.h"
#include "bb_apu.h"

#include <windows.h>
#include <mfapi.h>
#include <mferror.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <new>
#include <string>
#include <vector>

namespace {

template <typename T> void safe_release(T **value) {
    if (value && *value) {
        (*value)->Release();
        *value = nullptr;
    }
}

void set_error(wchar_t *text, size_t count, const wchar_t *message) {
    if (!text || !count) return;
    lstrcpynW(text, message ? message : L"Audio conversion failed.", static_cast<int>(count));
}

void set_hresult_error(wchar_t *text, size_t count, const wchar_t *prefix, HRESULT hr) {
    wchar_t system_message[384] = {0};
    wchar_t combined[640] = {0};
    FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
        static_cast<DWORD>(hr), 0, system_message,
        static_cast<DWORD>(sizeof(system_message) / sizeof(system_message[0])), nullptr);
    if (system_message[0]) {
        swprintf_s(combined, sizeof(combined) / sizeof(combined[0]), L"%ls\r\n\r\nWindows error 0x%08lX: %ls", prefix,
            static_cast<unsigned long>(hr), system_message);
    } else {
        swprintf_s(combined, sizeof(combined) / sizeof(combined[0]), L"%ls\r\n\r\nWindows error 0x%08lX.", prefix,
            static_cast<unsigned long>(hr));
    }
    set_error(text, count, combined);
}

bool write_bytes(HANDLE file, const void *data, DWORD size) {
    const unsigned char *cursor = static_cast<const unsigned char *>(data);
    while (size) {
        DWORD written = 0;
        if (!WriteFile(file, cursor, size, &written, nullptr) || !written) return false;
        cursor += written;
        size -= written;
    }
    return true;
}

void put_u16le(unsigned char *target, uint16_t value) {
    target[0] = static_cast<unsigned char>(value & 0xFFu);
    target[1] = static_cast<unsigned char>((value >> 8) & 0xFFu);
}

void put_u32le(unsigned char *target, uint32_t value) {
    target[0] = static_cast<unsigned char>(value & 0xFFu);
    target[1] = static_cast<unsigned char>((value >> 8) & 0xFFu);
    target[2] = static_cast<unsigned char>((value >> 16) & 0xFFu);
    target[3] = static_cast<unsigned char>((value >> 24) & 0xFFu);
}

bool write_canonical_wav_atomic(const wchar_t *destination, const int16_t *samples,
    uint64_t sample_count, wchar_t *error_text, size_t error_text_count) {
    std::wstring temporary;
    unsigned char header[44] = {0};
    HANDLE file = INVALID_HANDLE_VALUE;
    uint64_t data_size_64 = sample_count * sizeof(int16_t);
    bool ok = false;
    if (!destination || !samples || !sample_count || data_size_64 > 0xFFFFFFFFu - 36u) {
        set_error(error_text, error_text_count, L"The converted audio is too large for a standard PCM WAV file.");
        return false;
    }
    temporary = std::wstring(destination) + L".replacement.tmp";
    DeleteFileW(temporary.c_str());
    file = CreateFileW(temporary.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        set_hresult_error(error_text, error_text_count,
            L"Could not create the temporary converted WAV beside the replacement file.",
            HRESULT_FROM_WIN32(GetLastError()));
        return false;
    }
    memcpy(header, "RIFF", 4u);
    put_u32le(header + 4u, 36u + static_cast<uint32_t>(data_size_64));
    memcpy(header + 8u, "WAVEfmt ", 8u);
    put_u32le(header + 16u, 16u);
    put_u16le(header + 20u, 1u);
    put_u16le(header + 22u, 1u);
    put_u32le(header + 24u, BB_APU_SAMPLE_RATE);
    put_u32le(header + 28u, BB_APU_SAMPLE_RATE * 2u);
    put_u16le(header + 32u, 2u);
    put_u16le(header + 34u, 16u);
    memcpy(header + 36u, "data", 4u);
    put_u32le(header + 40u, static_cast<uint32_t>(data_size_64));
    ok = write_bytes(file, header, sizeof(header));
    if (ok) {
        const unsigned char *bytes = reinterpret_cast<const unsigned char *>(samples);
        uint64_t remaining = data_size_64;
        while (remaining && ok) {
            DWORD block = static_cast<DWORD>(std::min<uint64_t>(remaining, 1024u * 1024u));
            ok = write_bytes(file, bytes, block);
            bytes += block;
            remaining -= block;
        }
    }
    if (ok) ok = FlushFileBuffers(file) != FALSE;
    CloseHandle(file);
    if (!ok) {
        DeleteFileW(temporary.c_str());
        set_error(error_text, error_text_count, L"Windows could not finish writing the converted PCM WAV.");
        return false;
    }
    if (!MoveFileExW(temporary.c_str(), destination,
        MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
        HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
        DeleteFileW(temporary.c_str());
        set_hresult_error(error_text, error_text_count,
            L"The converted WAV was created, but Windows could not replace the saved Music Box file.", hr);
        return false;
    }
    return true;
}

bool get_pcm_type(IMFSourceReader *reader, uint16_t *channels, uint32_t *sample_rate,
    uint16_t *bits, uint32_t *block_align, wchar_t *error_text, size_t error_text_count) {
    IMFMediaType *type = nullptr;
    GUID subtype = GUID_NULL;
    UINT32 channel_value = 0;
    UINT32 rate_value = 0;
    UINT32 bits_value = 0;
    UINT32 align_value = 0;
    HRESULT hr = reader->GetCurrentMediaType(
        static_cast<DWORD>(MF_SOURCE_READER_FIRST_AUDIO_STREAM), &type);
    if (SUCCEEDED(hr)) hr = type->GetGUID(MF_MT_SUBTYPE, &subtype);
    if (SUCCEEDED(hr)) hr = type->GetUINT32(MF_MT_AUDIO_NUM_CHANNELS, &channel_value);
    if (SUCCEEDED(hr)) hr = type->GetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, &rate_value);
    if (SUCCEEDED(hr)) hr = type->GetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, &bits_value);
    if (SUCCEEDED(hr)) hr = type->GetUINT32(MF_MT_AUDIO_BLOCK_ALIGNMENT, &align_value);
    safe_release(&type);
    if (FAILED(hr)) {
        set_hresult_error(error_text, error_text_count,
            L"Windows decoded the file but did not provide a complete PCM audio format.", hr);
        return false;
    }
    if (subtype != MFAudioFormat_PCM || bits_value != 16u || channel_value < 1u ||
        channel_value > 8u || rate_value < 8000u || rate_value > 192000u ||
        align_value != channel_value * 2u) {
        set_error(error_text, error_text_count,
            L"Windows could not provide supported 16-bit PCM audio. The converter accepts decoded audio with 1 to 8 channels at 8 to 192 kHz.");
        return false;
    }
    *channels = static_cast<uint16_t>(channel_value);
    *sample_rate = rate_value;
    *bits = static_cast<uint16_t>(bits_value);
    *block_align = align_value;
    return true;
}

bool decode_with_media_foundation(const wchar_t *source_path, std::vector<int16_t> &pcm,
    uint16_t *channels, uint32_t *sample_rate, uint16_t *bits,
    wchar_t *error_text, size_t error_text_count) {
    IMFAttributes *attributes = nullptr;
    IMFSourceReader *reader = nullptr;
    IMFMediaType *requested = nullptr;
    std::vector<unsigned char> decoded_bytes;
    HRESULT hr = MFCreateAttributes(&attributes, 1u);
    if (SUCCEEDED(hr)) hr = attributes->SetUINT32(MF_READWRITE_DISABLE_CONVERTERS, FALSE);
    if (SUCCEEDED(hr)) hr = MFCreateSourceReaderFromURL(source_path, attributes, &reader);
    if (SUCCEEDED(hr)) hr = reader->SetStreamSelection(
        static_cast<DWORD>(MF_SOURCE_READER_ALL_STREAMS), FALSE);
    if (SUCCEEDED(hr)) hr = reader->SetStreamSelection(
        static_cast<DWORD>(MF_SOURCE_READER_FIRST_AUDIO_STREAM), TRUE);
    if (SUCCEEDED(hr)) hr = MFCreateMediaType(&requested);
    if (SUCCEEDED(hr)) hr = requested->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio);
    if (SUCCEEDED(hr)) hr = requested->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_PCM);
    if (SUCCEEDED(hr)) hr = requested->SetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, 16u);
    if (SUCCEEDED(hr)) hr = requested->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, TRUE);
    if (SUCCEEDED(hr)) hr = reader->SetCurrentMediaType(
        static_cast<DWORD>(MF_SOURCE_READER_FIRST_AUDIO_STREAM), nullptr,
        requested);
    safe_release(&requested);
    safe_release(&attributes);
    if (FAILED(hr)) {
        safe_release(&reader);
        set_hresult_error(error_text, error_text_count,
            L"Windows Media Foundation could not open or decode an audio stream from this file. Protected files and formats without an installed Windows decoder are not supported.", hr);
        return false;
    }
    uint32_t block_align = 0;
    if (!get_pcm_type(reader, channels, sample_rate, bits, &block_align, error_text, error_text_count)) {
        safe_release(&reader);
        return false;
    }
    const uint64_t maximum_bytes = static_cast<uint64_t>(BB_AUDIO_REPLACEMENT_MAX_SECONDS) *
        *sample_rate * block_align;
    try {
        decoded_bytes.reserve(static_cast<size_t>(std::min<uint64_t>(maximum_bytes, 16u * 1024u * 1024u)));
        for (;;) {
            DWORD actual_stream = 0;
            DWORD flags = 0;
            LONGLONG timestamp = 0;
            IMFSample *sample = nullptr;
            hr = reader->ReadSample(
                static_cast<DWORD>(MF_SOURCE_READER_FIRST_AUDIO_STREAM), 0u,
                &actual_stream, &flags, &timestamp, &sample);
            if (FAILED(hr)) {
                safe_release(&sample);
                break;
            }
            if (flags & MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED) {
                uint16_t changed_channels = 0;
                uint16_t changed_bits = 0;
                uint32_t changed_rate = 0;
                uint32_t changed_align = 0;
                if (!get_pcm_type(reader, &changed_channels, &changed_rate, &changed_bits,
                    &changed_align, error_text, error_text_count) ||
                    changed_channels != *channels || changed_rate != *sample_rate ||
                    changed_bits != *bits || changed_align != block_align) {
                    safe_release(&sample);
                    safe_release(&reader);
                    set_error(error_text, error_text_count,
                        L"The audio format changed partway through the file. Version 1.0.0 rejects changing-format streams so the saved replacement remains deterministic.");
                    return false;
                }
            }
            if (sample) {
                IMFMediaBuffer *buffer = nullptr;
                BYTE *bytes = nullptr;
                DWORD maximum = 0;
                DWORD current = 0;
                hr = sample->ConvertToContiguousBuffer(&buffer);
                if (SUCCEEDED(hr)) hr = buffer->Lock(&bytes, &maximum, &current);
                if (SUCCEEDED(hr) && current) {
                    if (decoded_bytes.size() + current > maximum_bytes) hr = MF_E_INVALID_FILE_FORMAT;
                    else decoded_bytes.insert(decoded_bytes.end(), bytes, bytes + current);
                }
                if (bytes) buffer->Unlock();
                safe_release(&buffer);
                safe_release(&sample);
                if (FAILED(hr)) break;
            }
            if (flags & MF_SOURCE_READERF_ENDOFSTREAM) break;
        }
    } catch (const std::bad_alloc &) {
        hr = E_OUTOFMEMORY;
    }
    safe_release(&reader);
    if (FAILED(hr)) {
        set_hresult_error(error_text, error_text_count,
            L"Windows could not finish decoding the selected audio. The file may be damaged or exceed the 20-minute conversion limit.", hr);
        return false;
    }
    if (decoded_bytes.empty() || decoded_bytes.size() % block_align) {
        set_error(error_text, error_text_count,
            L"The selected file did not produce a complete, non-empty PCM audio stream.");
        return false;
    }
    try {
        pcm.resize(decoded_bytes.size() / sizeof(int16_t));
    } catch (const std::bad_alloc &) {
        set_error(error_text, error_text_count, L"Not enough memory to hold the decoded audio.");
        return false;
    }
    memcpy(pcm.data(), decoded_bytes.data(), decoded_bytes.size());
    return true;
}

} // namespace

const wchar_t *bb_windows_media_open_filter(void) {
    return L"Supported audio (*.wav;*.mp3;*.m4a;*.mp4;*.aac;*.adts;*.wma)\0"
           L"*.wav;*.mp3;*.m4a;*.mp4;*.aac;*.adts;*.wma\0"
           L"WAV audio (*.wav)\0*.wav\0"
           L"MP3 audio (*.mp3)\0*.mp3\0"
           L"MPEG-4 or AAC audio (*.m4a;*.mp4;*.aac;*.adts)\0*.m4a;*.mp4;*.aac;*.adts\0"
           L"Windows Media Audio (*.wma)\0*.wma\0"
           L"All files\0*.*\0";
}

bool bb_windows_media_convert_to_music_box_wav(const wchar_t *source_path,
    const wchar_t *destination_path, BBWindowsAudioConversionInfo *info,
    wchar_t *error_text, size_t error_text_count) {
    HRESULT com_hr;
    HRESULT mf_hr;
    bool uninitialize_com = false;
    bool shutdown_mf = false;
    std::vector<int16_t> decoded;
    BBAudioReplacementPcm normalized = {nullptr, 0u};
    uint16_t channels = 0;
    uint16_t bits = 0;
    uint32_t sample_rate = 0;
    char normalize_error[256] = {0};
    bool ok = false;
    if (info) memset(info, 0, sizeof(*info));
    if (error_text && error_text_count) error_text[0] = 0;
    if (!source_path || !*source_path || !destination_path || !*destination_path) {
        set_error(error_text, error_text_count, L"No input or output path was supplied for audio conversion.");
        return false;
    }
    com_hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(com_hr)) uninitialize_com = true;
    else if (com_hr != RPC_E_CHANGED_MODE) {
        set_hresult_error(error_text, error_text_count, L"Windows could not initialize COM for audio conversion.", com_hr);
        return false;
    }
    mf_hr = MFStartup(MF_VERSION, MFSTARTUP_FULL);
    if (FAILED(mf_hr)) {
        set_hresult_error(error_text, error_text_count, L"Windows Media Foundation could not be started.", mf_hr);
        if (uninitialize_com) CoUninitialize();
        return false;
    }
    shutdown_mf = true;
    if (decode_with_media_foundation(source_path, decoded, &channels, &sample_rate, &bits,
        error_text, error_text_count)) {
        uint64_t frames = decoded.size() / channels;
        if (bb_audio_replacement_normalize_pcm16(decoded.data(), frames, channels, sample_rate,
            &normalized, normalize_error, sizeof(normalize_error))) {
            ok = write_canonical_wav_atomic(destination_path, normalized.samples,
                normalized.sample_count, error_text, error_text_count);
            if (ok && info) {
                info->input_channels = channels;
                info->input_bits_per_sample = bits;
                info->input_sample_rate = sample_rate;
                info->input_frames = frames;
                info->output_samples = normalized.sample_count;
                info->used_media_foundation = 1;
            }
        } else {
            int needed = MultiByteToWideChar(CP_UTF8, 0, normalize_error, -1, nullptr, 0);
            if (needed > 0) {
                std::vector<wchar_t> wide(static_cast<size_t>(needed));
                MultiByteToWideChar(CP_UTF8, 0, normalize_error, -1, wide.data(), needed);
                set_error(error_text, error_text_count, wide.data());
            } else set_error(error_text, error_text_count, L"The decoded audio could not be normalized.");
        }
    }
    bb_audio_replacement_pcm_free(&normalized);
    if (shutdown_mf) MFShutdown();
    if (uninitialize_com) CoUninitialize();
    return ok;
}
