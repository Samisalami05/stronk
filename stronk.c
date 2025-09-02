#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stronk.h"

#define PTR_SIZE 8

struct stronk {
	union {
		char* heap_ptr;
		char inline_arr[8];
	} arr;
	uint32_t length;
	uint32_t allocated;
};

stronk* stronk_init() {
	stronk* s = malloc(sizeof(stronk));
	s->length = 0;
	s->allocated = 0;
	return s;
}

char *get_arr(stronk *s) {
	if (s->allocated <= PTR_SIZE) {
		return &s->arr.inline_arr[0];
	} else return s->arr.heap_ptr;
}


void stronk_deinit(stronk* s) {
	if (get_arr(s) == s->arr.heap_ptr) free(s->arr.heap_ptr);
	free(s);
}

void resize(stronk *s, size_t new_size) {
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

void stronk_add(stronk* s, char* b, int l) {
	resize(s, s->length+l);
	char *arr = get_arr(s);
	for (int i = 0; i < l; i++) {
		arr[s->length+i] = b[i];
	}
	s->length += l;
}

void stronk_add_cstr(stronk* s, char* b) {
	stronk_add(s, b, strlen(b));
}

char* stronk_get_temp_cstr(stronk* s) {
	resize(s, s->length+1);
	char *arr = get_arr(s);
	arr[s->length] = 0;
	return arr;
}

char* stronk_alloc_cstr(stronk* s) {
	char *arr = get_arr(s);

	char* copy = malloc(s->length + 1);
	memcpy(copy, arr, s->length);
	copy[s->length] = '\0';
	return copy;
}

size_t stronk_len(stronk* s) {
	return s->length;
}

void stronk_reset(stronk* s) {
	s->length = 0;
	free(s->arr.heap_ptr);
}
