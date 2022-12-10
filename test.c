#include "parser.h"
#include "tokens.h"
#include "panic.h"

void test_into_nullterm() {
	char line[] = "The quick brown fox jumps over the lazy dog";
	String str = str_new(line);
	str.len = 10;
	char buf[100];
	str_into_nullterm(&str, buf, sizeof buf);
	printf("[%s]\n", buf);
	str_free(&str);
}

void test_cutoff() {
	char *line = "ADD 102 ; This adds the mailbox @102 to the accumulator";
	String str = str_new(line);
	char buf[100];
	str_cutoff(&str, 3);
	str_into_nullterm(&str, buf, sizeof buf);
	printf("Original: {%s}\nCut off at index 3: {%s}\n", line, buf);
	str_free(&str);
}

void test_tokenize() {
	char *line = "511 does this still work? ; and this?";
	String str = str_new(line);
	Tokens tokens = tokenize(&str);

	char buf[100];
	for (int i = 0; i < tokens.len; i++) {
		str_into_nullterm(&tokens.ptr[i], buf, sizeof buf);
		printf("{%s}\n", buf);
	}
	tok_free(&tokens);
}

void test_match_instr() {
	char *instr = "LDAT";
	String str = str_new(instr);
	printf("%s: %d\n", instr, match_instruction(&str));
	str_free(&str);
}

void test_parse_int() {
	char *integer = "12432183";
	String str = str_new(integer);
	printf("%s: %d\n", integer, parse_int(&str));
	str_free(&str);
}

void test_parse_line() {
	char *line = "ADD ; this adds the mailbox @102 to the accumulator";
	String str = str_new(line);
	Tokens tok = tokenize(&str);
	int instr = parse_instr(&tok);
	printf("%s:\n%d\n", line, instr);
	str_free(&str);
}

int main() {
//	test_into_nullterm();
//	test_cutoff();
//	test_tokenize();
//	test_match_instr();
//	test_parse_int();
//	test_parse_line();
	return 0;
}
