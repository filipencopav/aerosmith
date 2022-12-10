#ifndef __PARSER_H
#define __PARSER_H

#include <stdlib.h>
#include <string.h>
#include "./dynstring.h"
#include "./tokens.h"

Tokens tokenize(String* line);
int parse_int(String* str);

int match_instruction(String* instr);
int parse_instr(Tokens* tok);

#endif
