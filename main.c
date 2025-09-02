#include <stdio.h>
#include "string.h"

int main() {
	string* s = string_init();

	printf("first add\n");
	string_add(s, "hello", 5);

	printf("second add\n");
	string_add_cstr(s, " this is\n kinda crazy!\tthis is tabbed");
	
	//string_reset(s);
	printf("print add\n");

	printf("%s\n", string_get_temp_cstr(s));

	printf("%ld\n", string_len(s));

	string_deinit(s);
}
