#ifndef __TOKENS_AERO_H
#define __TOKENS_AERO_H

#include <stdlib.h>
#include <string.h>
#include "./dynstring.h"

typedef struct Tokens {
	size_t size;
	size_t len;
	String *ptr;
} Tokens;

Tokens tok_new();
void tok_push(Tokens* tok, String str);
void tok_free(Tokens* tok);

#endif
