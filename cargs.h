#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

static struct {
	int argc;
	char** argv;
} __cargs;

int __cargs_get_flag_index(const char* flag) {
	for(int i = 1; i < __cargs.argc; i++) {
		if(strcmp(flag, __cargs.argv[i]) == 0)
			return i;
	}

	return -1;
}

void cargs_init(int argc, char** argv) {
	assert(argc >= 1);
	__cargs.argc = argc;
	__cargs.argv = argv;
}

void cargs_get_flag_str(const char* flag, char* fallback, char** out) {
	int flag_index = __cargs_get_flag_index(flag);
	if(flag_index < 0 || (flag_index + 1) >= __cargs.argc) {
		*out = fallback;
		return;
	}

	*out = __cargs.argv[flag_index + 1];
}

void cargs_get_flag_int(const char* flag, int fallback, int* out) {
	int flag_index = __cargs_get_flag_index(flag);
	if(flag_index < 0 || (flag_index + 1) >= __cargs.argc) {
		*out = fallback;
		return;
	}

	*out = atoi(__cargs.argv[flag_index + 1]);
}

void cargs_get_flag_bool(const char* flag, bool* out) {
	int flag_index = __cargs_get_flag_index(flag);
	*out = flag_index >= 0;
}