cmake_minimum_required(VERSION 3.20)
project(BubbleBobbleStaticRecomp VERSION 1.1.0 LANGUAGES C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
  # Keep the Windows package portable on clean Windows 10/11 systems.
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if(WIN32)
  include(FetchContent)
  set(SDL_SHARED OFF CACHE BOOL "" FORCE)
  set(SDL_STATIC ON CACHE BOOL "" FORCE)
  set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
  set(SDL_TESTS OFF CACHE BOOL "" FORCE)
  set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(bb_sdl
    URL "https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.10.zip"
    URL_HASH "SHA256=30DCE54890B17544A35E4521274762016AF6ED59C2183B896EF5E6693E97FB6C"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  FetchContent_MakeAvailable(bb_sdl)
  FetchContent_GetProperties(bb_sdl SOURCE_DIR BB_SDL_SOURCE_DIR)
endif()
set(BB_DIRECT_C
  generated/direct_c/bb_generated_direct.c
  generated/direct_c/bb_generated_bank00.c
  generated/direct_c/bb_generated_bank01.c
  generated/direct_c/bb_generated_bank02.c
  generated/direct_c/bb_generated_bank03.c
  generated/direct_c/bb_generated_bank04.c
  generated/direct_c/bb_generated_bank05.c
  generated/direct_c/bb_generated_bank06.c
  generated/direct_c/bb_generated_bank07.c)
set(BB_SEMANTICS_C
  generated/semantics/bb_generated_semantics.c
  generated/semantics/bb_generated_semantics_compact.c
  generated/semantics/bb_generated_semantics_bank00.c
  generated/semantics/bb_generated_semantics_bank01.c
  generated/semantics/bb_generated_semantics_bank02.c
  generated/semantics/bb_generated_semantics_bank03.c
  generated/semantics/bb_generated_semantics_bank04.c
  generated/semantics/bb_generated_semantics_bank05.c
  generated/semantics/bb_generated_semantics_bank06.c
  generated/semantics/bb_generated_semantics_bank07.c)
add_library(bb_core STATIC
  src/common/bb_hash.c src/common/bb_rom.c
  src/mods/bb_mods.c src/mods/bb_music_box.c src/mods/bb_sound_catalog.c src/mods/bb_audio_replacement.c
  src/mapper/bb_mmc1.c
  src/player/bb_runtime.c src/player/bb_renderer.c src/player/bb_snapshot.c src/player/bb_apu.c src/player/bb_wav.c src/player/bb_audio_queue.c src/player/bb_ppu_checkpoint.c
  ${BB_SEMANTICS_C})
target_include_directories(bb_core PUBLIC
  src/common src/mapper src/static src/player src/mods
  generated/structural generated/direct_c generated/semantics)
if(MSVC)
  target_compile_definitions(bb_core PRIVATE _CRT_SECURE_NO_WARNINGS)
  # Generated 6502 semantics deliberately truncate 16-bit constants when
  # reproducing 8-bit hardware writes; MSVC reports those as C4310.
  target_compile_options(bb_core PRIVATE /W4 /WX /wd4310)
  # Factored helper parameters preserve the original unsigned literal type;
  # their already-bounded PC/address values then narrow at the same explicit
  # generated assignment/call sites. Limit C4244 suppression to this file.
  set_source_files_properties(
    generated/semantics/bb_generated_semantics_compact.c
    PROPERTIES COMPILE_OPTIONS "/wd4244")
else()
  target_compile_options(bb_core PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# Structural/direct context intelligence remains available to development
# checks, but is deliberately excluded from the production core and Launcher.
# The production dispatcher retains every fixed bank:PC case and fails closed.
add_library(bb_static_analysis STATIC
  src/static/bb_static_catalog.c
  generated/structural/bb_static_contexts.c
  ${BB_DIRECT_C})
target_include_directories(bb_static_analysis PUBLIC
  src/common src/static
  generated/structural generated/direct_c)
if(MSVC)
  target_compile_definitions(bb_static_analysis PRIVATE _CRT_SECURE_NO_WARNINGS)
  target_compile_options(bb_static_analysis PRIVATE /W4 /WX)
else()
  target_compile_options(bb_static_analysis PRIVATE
    -Wall -Wextra -Wpedantic -Werror)
endif()

# Production clients use only this opaque facade. The historical runtime and
# generated headers remain private implementation details of the facade.
add_library(bb_static_core STATIC
  runtime/core/src/bb_static_core.c)
target_include_directories(bb_static_core
  PUBLIC runtime/core/include
  PRIVATE
    src/common src/mapper src/static src/player src/mods
    generated/structural generated/direct_c generated/semantics)
target_link_libraries(bb_static_core PRIVATE bb_core)
if(MSVC)
  target_compile_definitions(bb_static_core PRIVATE _CRT_SECURE_NO_WARNINGS)
  target_compile_options(bb_static_core PRIVATE /W4 /WX)
else()
  target_compile_options(bb_static_core PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_executable(bb-static-core-api-selftest
  runtime/core/tests/bb_static_core_api_selftest.c)
target_link_libraries(bb-static-core-api-selftest PRIVATE bb_static_core)
add_executable(bb-rom-audit src/tools/bb_rom_audit.c)
target_link_libraries(bb-rom-audit PRIVATE bb_core)
add_executable(bb-mmc1-selftest src/tools/bb_mmc1_selftest.c)
target_link_libraries(bb-mmc1-selftest PRIVATE bb_core)
add_executable(bb-hash-selftest src/tools/bb_hash_selftest.c)
target_link_libraries(bb-hash-selftest PRIVATE bb_core)
add_executable(bb-static-catalog-selftest src/tools/bb_static_catalog_selftest.c)
target_link_libraries(bb-static-catalog-selftest PRIVATE bb_static_analysis bb_core)
add_executable(bb-generated-direct-selftest src/tools/bb_generated_direct_selftest.c)
target_link_libraries(bb-generated-direct-selftest PRIVATE bb_static_analysis)
add_executable(bb-semantics-selftest src/tools/bb_semantics_selftest.c)
target_link_libraries(bb-semantics-selftest PRIVATE bb_core)
add_executable(bb-ppu-selftest src/tools/bb_ppu_selftest.c)
target_link_libraries(bb-ppu-selftest PRIVATE bb_core)
add_executable(bb-renderer-selftest src/tools/bb_renderer_selftest.c)
target_link_libraries(bb-renderer-selftest PRIVATE bb_core)
add_executable(bb-structural-contract-selftest src/tools/bb_structural_contract_selftest.c)
target_link_libraries(bb-structural-contract-selftest PRIVATE bb_static_analysis)
add_executable(bb-snapshot-selftest src/tools/bb_snapshot_selftest.c)
target_link_libraries(bb-snapshot-selftest PRIVATE bb_core)
add_executable(bb-apu-selftest src/tools/bb_apu_selftest.c)
target_link_libraries(bb-apu-selftest PRIVATE bb_core)
add_executable(bb-audio-queue-selftest src/tools/bb_audio_queue_selftest.c)
target_link_libraries(bb-audio-queue-selftest PRIVATE bb_core)
add_executable(bb-audio-snapshot-selftest src/tools/bb_audio_snapshot_selftest.c)
target_link_libraries(bb-audio-snapshot-selftest PRIVATE bb_core)
add_executable(bb-music-box-selftest src/tools/bb_music_box_selftest.c)
target_link_libraries(bb-music-box-selftest PRIVATE bb_core)
add_executable(bb-music-box-render src/tools/bb_music_box_render.c)
target_link_libraries(bb-music-box-render PRIVATE bb_core)
add_executable(bb-audio-replacement-selftest src/tools/bb_audio_replacement_selftest.c)
target_link_libraries(bb-audio-replacement-selftest PRIVATE bb_core)
add_executable(bb-audio-replacement-demo src/tools/bb_audio_replacement_demo.c)
target_link_libraries(bb-audio-replacement-demo PRIVATE bb_core)
add_executable(bb-audio-normalize-selftest src/tools/bb_audio_normalize_selftest.c)
target_link_libraries(bb-audio-normalize-selftest PRIVATE bb_core)
add_executable(bb-sound-driver-trace src/tools/bb_sound_driver_trace.c)
target_link_libraries(bb-sound-driver-trace PRIVATE bb_core)
add_executable(bb-sound-catalog-selftest src/tools/bb_sound_catalog_selftest.c)
target_link_libraries(bb-sound-catalog-selftest PRIVATE bb_core)
add_executable(bb-sound-catalog-render src/tools/bb_sound_catalog_render.c)
target_link_libraries(bb-sound-catalog-render PRIVATE bb_core)
add_executable(bb-ppu-checkpoint-selftest src/tools/bb_ppu_checkpoint_selftest.c)
target_link_libraries(bb-ppu-checkpoint-selftest PRIVATE bb_core)
if(WIN32)
  add_executable(BubbleBobbleLauncher WIN32
    src/gui/bb_windows_launcher.cpp
    src/gui/bb_windows_live.cpp
    src/gui/bb_bmp_writer.c
    src/gui/bb_audio_output_sdl3.cpp
    src/gui/bb_video_output_sdl3.cpp
    src/gui/launcher_version.rc)
  target_compile_definitions(BubbleBobbleLauncher PRIVATE
    WIN32_LEAN_AND_MEAN NOMINMAX)
  target_include_directories(BubbleBobbleLauncher PRIVATE
    src/gui src/common runtime/core/include)
  target_link_libraries(BubbleBobbleLauncher PRIVATE
    bb_static_core SDL3::SDL3-static comdlg32 user32 gdi32)
  set_target_properties(BubbleBobbleLauncher PROPERTIES
    OUTPUT_NAME "Launcher"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release")
  if(MSVC)
    target_compile_definitions(BubbleBobbleLauncher PRIVATE
      _CRT_SECURE_NO_WARNINGS)
    target_compile_options(BubbleBobbleLauncher PRIVATE /W4 /WX)
  else()
    target_compile_options(BubbleBobbleLauncher PRIVATE
      -Wall -Wextra -Wpedantic -Werror)
  endif()
  add_custom_command(TARGET BubbleBobbleLauncher POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${CMAKE_SOURCE_DIR}/README.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/README.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${CMAKE_SOURCE_DIR}/VERSION.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/VERSION.txt"
    COMMAND "${CMAKE_COMMAND}" -E make_directory
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/Rom"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${CMAKE_SOURCE_DIR}/Rom/Readme.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/Rom/Readme.txt"
    COMMAND "${CMAKE_COMMAND}" -E make_directory
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/Saves"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${CMAKE_SOURCE_DIR}/Saves/Readme.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/Saves/Readme.txt"
    COMMAND "${CMAKE_COMMAND}" -E make_directory
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/Screenshots"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${CMAKE_SOURCE_DIR}/Screenshots/Readme.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/Screenshots/Readme.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${BB_SDL_SOURCE_DIR}/LICENSE.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/SDL-LICENSE.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      "${CMAKE_SOURCE_DIR}/third_party/gamecontrollerdb.txt"
      "$<TARGET_FILE_DIR:BubbleBobbleLauncher>/gamecontrollerdb.txt"
    VERBATIM)
endif()
enable_testing()
add_test(NAME hash-primitives COMMAND bb-hash-selftest)
add_test(NAME mmc1-model COMMAND bb-mmc1-selftest)
add_test(NAME generated-direct-c-link COMMAND bb-generated-direct-selftest)
add_test(NAME structural-contracts COMMAND bb-structural-contract-selftest)
add_test(NAME generated-semantic-execution COMMAND bb-semantics-selftest)
add_test(NAME palette-renderer COMMAND bb-renderer-selftest)
add_test(NAME ppu-mmc1-rendering COMMAND bb-ppu-selftest)
add_test(NAME snapshot-protocol COMMAND bb-snapshot-selftest)
add_test(NAME ntsc-apu-dmc COMMAND bb-apu-selftest)
add_test(NAME bounded-audio-queue COMMAND bb-audio-queue-selftest)
add_test(NAME active-audio-snapshot COMMAND bb-audio-snapshot-selftest)
add_test(NAME mods-and-music-box COMMAND bb-music-box-selftest)
add_test(NAME exact-rom-sound-catalog COMMAND bb-sound-catalog-selftest)
add_test(NAME predecoded-audio-replacement COMMAND bb-audio-replacement-selftest)
add_test(NAME audio-import-normalization COMMAND bb-audio-normalize-selftest)
add_test(NAME ppu-checkpoint COMMAND bb-ppu-checkpoint-selftest)
