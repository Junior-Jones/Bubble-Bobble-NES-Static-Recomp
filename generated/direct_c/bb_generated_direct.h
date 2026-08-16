#ifndef BB_GENERATED_DIRECT_H
#define BB_GENERATED_DIRECT_H
#include <stddef.h>
#include <stdint.h>
typedef enum BBGeneratedKind { BB_GEN_NORMAL=0, BB_GEN_BRANCH=1, BB_GEN_JUMP=2, BB_GEN_CALL=3, BB_GEN_RETURN=4, BB_GEN_RTI=5, BB_GEN_STOP=6, BB_GEN_TRAP=7 } BBGeneratedKind;
typedef struct BBGeneratedStep { uint8_t bank; uint16_t pc; uint8_t opcode; uint8_t size; uint8_t cycles; uint8_t mode_id; uint8_t kind; uint16_t operand; uint16_t target; uint16_t fallthrough; } BBGeneratedStep;
int bb_generated_step(uint8_t bank,uint16_t pc,BBGeneratedStep*out);
size_t bb_generated_context_count(void);
#endif
