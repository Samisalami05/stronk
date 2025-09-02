#pragma once

#include <stdint.h>

typedef struct stronk stronk;

stronk* stronk_init();

void stronk_deinit(stronk* s);

void stronk_add(stronk* s, char* b, int l);

void stronk_add_cstr(stronk* s, char* b);

char* stronk_get_temp_cstr(stronk* s);

char* stronk_alloc_cstr(stronk* s);

size_t stronk_len(stronk* s);

void stronk_reset(stronk* s);
