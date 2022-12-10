#ifndef __DYNSTRING_H
#define __DYNSTRING_H

#include <string.h>
#include <stdlib.h>
#include "./panic.h"

typedef struct String {
	size_t size;
	size_t len;
	char *ptr;
} String;

typedef struct Slice {
	char* begin;
	char* end;
} Slice;

String str_new(const char* str);
String str_from_slice(Slice);
void str_free(String* str);

char str_pop(String* str);
void str_push(String* str, char c);
void str_cutoff(String* str, size_t index);
char *str_findchar(String* str, char c);
void str_into_nullterm(String* str, char *buf, size_t bufsize);

#endif
