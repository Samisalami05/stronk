#include <stdio.h>
#include <stronk.h>

int main() {
	stronk* s = stronk_init();

	printf("first add\n");
	stronk_add(s, "hello", 5);

	printf("second add\n");
	stronk_add_cstr(s, " this is\n kinda crazy!\tthis is tabbed");
	
	//stronk_reset(s);
	printf("print add\n");

	printf("%s\n", stronk_get_temp_cstr(s));

	printf("%ld\n", stronk_len(s));

	stronk_deinit(s);
}
