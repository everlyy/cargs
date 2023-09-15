# cargs

Simple header to parse command line arguments in C

# Run example

To run the example just execute `run.sh` in your terminal.
It has the following flags:
 * `-s <string>` Gets a string
 * `-i <int>` Gets an int
 * `-b` Gets a bool, false if the flag isn't present

# Usage

```C
#include "cargs.h"

int main(int argc, char** argv) {
	cargs_init(argc, argv);

	char* message;
	cargs_get_flag_str("--message", "Hi!!", &message);

	printf("Message: %s\n", message);
	return 0;
}
```

Take a look at `example.c` for more examples.