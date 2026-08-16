#include "bb_input_script.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_value(const char *text, unsigned long maximum, unsigned long *out) {
    char *end = NULL;
    unsigned long value = strtoul(text, &end, 0);
    if (end == text || value > maximum) return 0;
    while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') end++;
    if (*end != '\0') return 0;
    *out = value;
    return 1;
}

int bb_input_script_load(const char *path, BBInputScript *script, char *error, size_t error_cap) {
    FILE *f;
    char line[256];
    unsigned line_number = 0;
    if (!path || !script) return 0;
    memset(script, 0, sizeof(*script));
    f = fopen(path, "rb");
    if (!f) { if (error && error_cap) snprintf(error, error_cap, "could not open input script"); return 0; }
    while (fgets(line, sizeof(line), f)) {
        char *first, *second, *third, *hash;
        unsigned long frame, p1, p2;
        line_number++;
        hash = strchr(line, '#'); if (hash) *hash = '\0';
        first = line;
        while (*first == ' ' || *first == '\t') first++;
        if (*first == '\0' || *first == '\r' || *first == '\n') continue;
        second = strchr(first, ',');
        if (!second) { if (error && error_cap) snprintf(error,error_cap,"line %u: expected frame,p1,p2",line_number); fclose(f); return 0; }
        *second++ = '\0';
        third = strchr(second, ',');
        if (!third) { if (error && error_cap) snprintf(error,error_cap,"line %u: expected third field",line_number); fclose(f); return 0; }
        *third++ = '\0';
        if (!parse_value(first, 0xFFFFFFFFul, &frame) || !parse_value(second, 0xFFul, &p1) || !parse_value(third, 0xFFul, &p2)) {
            if (error && error_cap) snprintf(error,error_cap,"line %u: invalid numeric value",line_number);
            fclose(f);
            return 0;
        }
        if (script->count >= BB_INPUT_SCRIPT_MAX_EVENTS) { if (error && error_cap) snprintf(error,error_cap,"too many input events"); fclose(f); return 0; }
        if (script->count && frame <= script->events[script->count-1u].frame) { if (error && error_cap) snprintf(error,error_cap,"line %u: frames must increase",line_number); fclose(f); return 0; }
        script->events[script->count].frame = (uint32_t)frame;
        script->events[script->count].player1 = (uint8_t)p1;
        script->events[script->count].player2 = (uint8_t)p2;
        script->count++;
    }
    fclose(f);
    if (script->count == 0u) { if (error && error_cap) snprintf(error,error_cap,"input script is empty"); return 0; }
    return 1;
}

void bb_input_script_state_at(const BBInputScript *script, uint32_t frame, uint8_t *player1, uint8_t *player2) {
    uint8_t p1 = 0u, p2 = 0u;
    if (script && script->count) {
        size_t lo = 0u, hi = script->count;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2u;
            if (script->events[mid].frame <= frame) lo = mid + 1u;
            else hi = mid;
        }
        if (lo > 0u) {
            p1 = script->events[lo - 1u].player1;
            p2 = script->events[lo - 1u].player2;
        }
    }
    if (player1) *player1 = p1;
    if (player2) *player2 = p2;
}

int bb_input_script_selftest(void) {
    BBInputScript script;
    uint8_t p1,p2;
    memset(&script,0,sizeof(script));
    script.events[0]=(BBInputEvent){0u,0u,0u};
    script.events[1]=(BBInputEvent){10u,8u,0u};
    script.events[2]=(BBInputEvent){12u,0u,0u};
    script.count=3u;
    bb_input_script_state_at(&script,0u,&p1,&p2); if(p1||p2)return 1;
    bb_input_script_state_at(&script,10u,&p1,&p2); if(p1!=8u||p2)return 2;
    bb_input_script_state_at(&script,50u,&p1,&p2); if(p1||p2)return 3;
    return 0;
}
