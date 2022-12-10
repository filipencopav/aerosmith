#include "tokens.h"

Tokens tok_new() {
	Tokens new = { .len = 0, .size = 4 };
	new.ptr = (String *) malloc(new.size * sizeof(String));
	return new;
}

void tok_push(Tokens* tok, String str) {
	if (tok->size == tok->len) {
		tok->size *= 2;
		tok->ptr = (String *) realloc(tok->ptr, tok->size * sizeof(String));
	}
	tok->ptr[tok->len++] = str;
}

void tok_free(Tokens* tok) {
	for (size_t i = 0; i < tok->len; i++) {
		str_free(&tok->ptr[i]);
	}
	free(tok->ptr);
}
