#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

#define PTR_SIZE 8

struct string {
	union {
		char* heap_ptr;
		char inline_arr[8];
	} arr;
	uint32_t length;
	uint32_t allocated;
};

string* string_init() {
	string* s = malloc(sizeof(string));
	s->length = 0;
	s->allocated = 0;
	return s;
}

char *get_arr(string *s) {
	if (s->allocated <= PTR_SIZE) {
		return &s->arr.inline_arr[0];
	} else return s->arr.heap_ptr;
}


void string_deinit(string* s) {
	if (get_arr(s) == s->arr.heap_ptr) free(s->arr.heap_ptr);
	free(s);
}

void resize(string *s, size_t new_size) {
	if (new_size <= 8) return; // use inline

	size_t before = s->allocated;
	if (new_size > s->allocated) {
		if (s->allocated*2 >= new_size) {
			s->allocated *= 2;
		} else {
			uint8_t bit = 64 - __builtin_clz((uint64_t)(new_size-1));
			s->allocated = 1 << bit;
		}
	}
	if (before != s->allocated) {
		if (before <= 8) {
			char *new_ptr = malloc(s->allocated);
			memcpy(new_ptr, s->arr.inline_arr, 8);
			s->arr.heap_ptr = new_ptr;
		} else {
			s->arr.heap_ptr = realloc(s->arr.heap_ptr, s->allocated);
		}
	}
}

void string_add(string* s, char* b, int l) {
	resize(s, s->length+l);
	char *arr = get_arr(s);
	for (int i = 0; i < l; i++) {
		arr[s->length+i] = b[i];
	}
	s->length += l;
}

void string_add_cstr(string* s, char* b) {
	string_add(s, b, strlen(b));
}

char* string_get_temp_cstr(string* s) {
	resize(s, s->length+1);
	char *arr = get_arr(s);
	arr[s->length] = 0;
	return arr;
}

char* string_alloc_cstr(string* s) {
	char *arr = get_arr(s);

	char* copy = malloc(s->length + 1);
	memcpy(copy, arr, s->length);
	copy[s->length] = '\0';
	return copy;
}

size_t string_len(string* s) {
	return s->length;
}

void string_reset(string* s) {
	s->length = 0;
	free(s->arr.heap_ptr);
}
