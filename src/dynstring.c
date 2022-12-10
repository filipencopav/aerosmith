#include "./includes/dynstring.h"

String str_new(const char* str) {
	String new;
	new.len = strlen(str);
	new.size = new.len + 1;
	new.ptr = (char*) malloc(new.size * sizeof (char));
	for (size_t i = 0; i < new.size; i++) {
		new.ptr[i] = str[i];
	}
	return new;
}

String str_from_slice(Slice slice) {
	String new;
	new.len = (slice.end - slice.begin) + 1;
	new.size = new.len + 1;
	new.ptr = (char*) malloc (new.size * sizeof (char));
	for (size_t i = 0; i < new.len; i++) {
		new.ptr[i] = slice.begin[i];
	}
	return new;
}

void str_free(String* str) {
	free(str->ptr);
}

char str_pop(String* str) {
	if (str->len < 1)
		panic("String too short to pop anything from it.");
	return str->ptr[--str->len];
}

void str_push(String* str, char c) {
	if (str->size == str->len) {
		str->size *= 2;
		str->ptr = (char*) realloc(str->ptr, str->size * sizeof (char));
	}
	str->ptr[str->len++] = c;
}

void str_cutoff(String* str, size_t index) {
	str->len = index < str->len ? index : str->len;
}

char *str_findchar(String* str, char c) {
	char *res = NULL;
	for (size_t i = 0; i < str->len; i++) {
		if (str->ptr[i] == c) {
			res = str->ptr+i;
			break;
		}
	}
	return res;
}

void str_into_nullterm(String *str, char *buf, size_t bufsize) {
	size_t len = str->len < bufsize-1 ? str->len : bufsize-1;
	for (size_t i = 0; i < len; i++) {
		buf[i] = str->ptr[i];
	}
	buf[len] = 0;
}
