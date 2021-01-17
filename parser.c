#include <stdint.h>
#include <stdlib.h>

#include "parser.h"

struct DynArraySlice {
	size_t len;
	size_t size;
	Slice* arr;
}

#define ASSERT_MSG(expr, message) assert_message(expr, message, __FILE__, __LINE__)
void assert_message(int expr, const char* message, const char* file, int line) {
	if (!expr) {
		fprintf(stderr, "Assertion failed in file '%s', on line '%d': %s\n",
		        file, line, message);
		exit(1);
	}
}

void DynArraySlice_init(DynArraySlice *vec, size_t initial_size) {
	ASSERT_MSG(initial_size != 0, "Dynamic array initial size cannot be 0!");
	vec->len = 0;
	vec->size = initial_size;
	vec->arr = malloc(sizeof(int) * initial_size);
}

void DynArraySlice_push(DynArraySlice *vec, Slice elem) {
	if (vec->len == vec->size) {
		vec->size *= 2;
		vec->arr = realloc(vec->arr, vec->size);
	}
	vec->arr[vec->len] = elem;
	vec->len++;
}

Slice DynArraySlice_pop(DynArraySlice *vec) {
	vec->len--;
	return vec->arr[vec->len];
}

void DynArraySlice_free(DynArraySlice *vec) {
	if (vec == NULL) {
		return;
	}
	for (size_t i = 0; i < vec->len; i++) {
		free(vec->arr[i]);
	}
	free(vec->arr);
	vec->len=0;
	vec->size=0;
}

// TO BE USED IN SWITCH ONLY
#define WHITESPACE\
	' ':\
	case '\n':\
	case '\t'
const char* tokenize(char* line) {
	if (line == NULL) return NULL;
	size_t i, chars = 0;
	// TODO: finish this
}
