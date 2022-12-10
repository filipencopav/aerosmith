#include "panic.h"

void panic(const char *msg) {
	fprintf(stderr, "[ERROR]: %s\n", msg);
	exit(1);
}
