#include <stdio.h>
#include "cargs.h"

int main(int argc, char** argv) {
	cargs_init(argc, argv);

	char* str;
	int i;
	bool b;

	cargs_get_flag_str("-s", "Hello, world!", &str);
	cargs_get_flag_int("-i", 7, &i);
	cargs_get_flag_bool("-b", &b);

	printf("str : %s\n", str);
	printf("i   : %d\n", i);
	printf("bool: %s\n", b ? "true" : "false");

	return 0;
}