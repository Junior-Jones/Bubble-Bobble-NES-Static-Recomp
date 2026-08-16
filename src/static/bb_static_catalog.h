#ifndef BB_STATIC_CATALOG_H
#define BB_STATIC_CATALOG_H
#include "bb_rom.h"
#include "bb_static_contexts.h"
#include <stddef.h>
#include <stdint.h>
int bb_static_catalog_verify_rom(const BBRom *rom, size_t *checked, char *error, size_t error_cap);
int bb_static_catalog_allows(uint8_t physical_bank, uint16_t pc);
#endif
