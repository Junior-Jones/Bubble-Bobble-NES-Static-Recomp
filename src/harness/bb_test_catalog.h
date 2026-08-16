#ifndef BB_TEST_CATALOG_H
#define BB_TEST_CATALOG_H
#include <stddef.h>
typedef struct BBTestDefinition { const char *id; const char *name; const char *description; int headed_supported; int gameplay_required; } BBTestDefinition;
extern const BBTestDefinition bb_tests[];
extern const size_t bb_test_count;
const BBTestDefinition *bb_test_find(const char *id);
#endif
