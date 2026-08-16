#ifndef BB_STATIC_CONTEXTS_H
#define BB_STATIC_CONTEXTS_H
#include <stddef.h>
#include <stdint.h>
typedef struct BBStaticContext { uint8_t bank; uint16_t pc; uint8_t opcode; uint8_t size; uint8_t cycles; uint32_t mnemonic_tag; } BBStaticContext;
extern const BBStaticContext bb_static_contexts[];
extern const size_t bb_static_context_count;
const BBStaticContext *bb_static_context_find(uint8_t bank,uint16_t pc);
#endif
