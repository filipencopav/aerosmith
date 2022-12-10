#include "panic.h"
#include "parser.h"
#include "dynstring.h"

int is_whitespace(char c) {
	switch (c) {
	case ' ':
	case '\t':
		return 1;
		break;
	}
	return 0;
}

char *consume_whitespace(char *ptr, String* str) {
	while (ptr < str->ptr + str->len) {
		if (!is_whitespace(*ptr)) {
			break;
		}
		ptr++;
	}

	return ptr;
}

Tokens tokenize(String* line) {
	// first, cut off comments
	size_t comment_pos;
	char *comment_ptr = str_findchar(line, ';');
	if (comment_ptr != NULL) {
		comment_pos = comment_ptr - line->ptr;
		str_cutoff(line, comment_pos);
	}

	Tokens tokens = tok_new();

	int state = 0; // 0: consume whitespace, 1: make token
	Slice token = { .begin = line->ptr, .end = line->ptr };
	while (state != -1) {
		if (state) {
			state = -1;
			size_t i;
			for (i = 1; i < (line->ptr + line->len) - token.begin; i++) {
				if (is_whitespace(token.begin[i])) {
					state = 0;
					break;
				}
			}
			if (((line->ptr + line->len) - token.begin) != 0) {
				token.end = token.begin + (i - 1);
				tok_push(&tokens, str_from_slice(token));
				token.begin = ++token.end;
			}
		} else {
			token.begin = consume_whitespace(token.begin, line);
			token.end = token.begin;
			state = 1;
		}
	}

	return tokens;
}

int match_instruction(String* instr) {
	char *instructions[] = {
		"COB",
		"ADD",
		"SUB",
		"STA",
		"DAT",
		"LDA",
		"BRA",
		"BRZ",
		"BRP",
		"INP",
		"OUT"
	};

	char buf[5];
	str_into_nullterm(instr, buf, sizeof buf);
	for (int i = 0; i < 11; i++) {
		if (strcmp(buf, instructions[i]) == 0) {
			return i;
		}
	}

	return -1;
}

int power(int base, size_t power) {
	int res = 1;
	for (int i = 0; i < power; i++) {
		res *= base;
	}
	return res;
}

int parse_int(String* str) {
	int res = 0;
	for (size_t i = 0; i < str->len; i++) {
		res += power(10, str->len-i-1) * (str->ptr[i] - 48);
	}
	return res;
}

int parse_instr(Tokens* tok) {
	if (tok->len > 2)
		panic("Too many arguments!");
	if (tok->len == 0)
		panic("Empty instruction.");

	int instr = match_instruction(&tok->ptr[0]);
	int addr;
	switch(instr) {
	case 0:
		return 0;
	case 1:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
		if (tok->len < 2)
			panic("Not enough arguments!");
		addr = parse_int(&tok->ptr[1]);
		return instr * 100 + (addr % 100);
	case 4:
		addr = parse_int(&tok->ptr[1]);
		return addr;
	case 9:
		return 901;
	case 10:
		return 902;
	default:
		panic("Unknown instruction!");
	}
}


/*
 * COB 0
 * ADD 1
 * SUB 2
 * STA 3
 * empty 4
 * LDA 5
 * BRA 6
 * BRZ 7
 * BRP 8
 * INP 9
 * OUT 10
 */
