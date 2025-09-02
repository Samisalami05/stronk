#pragma once

#include <stdint.h>

typedef struct string string;

string* string_init();

void string_deinit(string* s);

void string_add(string* s, char* b, int l);

void string_add_cstr(string* s, char* b);

char* string_get_temp_cstr(string* s);

char* string_alloc_cstr(string* s);

size_t string_len(string* s);

void string_reset(string* s);
