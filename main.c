#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "src/includes/parser.h"

typedef struct Aerosmith {
	int accumulator;
	int program_counter;
	int mailboxes[100];
} Aerosmith;

void cob(size_t addr, Aerosmith *aero) {
	puts("[COB]");
	exit(0);
}

void add(size_t addr, Aerosmith *aero) {
	aero->accumulator += aero->mailboxes[addr];
}

void sub(size_t addr, Aerosmith *aero) {
	aero->accumulator -= aero->mailboxes[addr];
}

void sta(size_t addr, Aerosmith *aero) {
	aero->mailboxes[addr] = aero->accumulator;
}

void lda(size_t addr, Aerosmith *aero) {
	aero->accumulator = aero->mailboxes[addr];
}

void bra(size_t addr, Aerosmith *aero) {
	aero->program_counter = addr;
}

void brz(size_t addr, Aerosmith *aero) {
	if (aero->accumulator == 0) {
		aero->program_counter = addr;
	}
}

void brp(size_t addr, Aerosmith *aero) {
	if (aero->accumulator >= 0) {
		aero->program_counter = addr;
	}
}

void inp(size_t addr, Aerosmith *aero) {
	printf("[INP]: ");
	scanf("%d", &(aero->accumulator));
}

void out(size_t addr, Aerosmith *aero) {
	printf("[OUT]: %d\n", aero->accumulator);
}

void io(size_t addr, Aerosmith *aero) {
	if (addr == 2) {
		inp(addr, aero);
	} else if (addr == 1) {
		out(addr, aero);
	}
}

void empty(size_t addr, Aerosmith *aero) {}

void read_instructions(FILE *in_file, int mailboxes[], size_t mailboxes_len) {
	size_t i = 0;
//	for (; i < mailboxes_len; i++)
//		if (fscanf(in_file, " %d ", mailboxes + i) == EOF)
//			break;

	while(!feof(in_file)) {
		String line = str_new("");
		Tokens tokens;
		for (char c = fgetc(in_file); c != '\n' && !feof(in_file); c = fgetc(in_file)) {
			str_push(&line, c);
		}
		tokens = tokenize(&line);
		if (tokens.len != 0) {
			int instr = parse_instr(&tokens);
			mailboxes[i] = instr;
			i++;
		}
		tok_free(&tokens);
		str_free(&line);
	}
}

void (*instructions[10])(size_t, Aerosmith *) = {
	cob,
	add,
	sub,
	sta,
	empty,
	lda,
	bra,
	brz,
	brp,
	io,
};

void run(Aerosmith *aero) {
	size_t addr = aero->mailboxes[aero->program_counter] % 100;
	size_t instr = aero->mailboxes[aero->program_counter] / 100;
	aero->program_counter++;
	instructions[instr](addr, aero);
}

int main() {
	Aerosmith aero;
	aero.program_counter = 0;
	aero.accumulator = 0;
	FILE *in_file = fopen("instr.txt", "r");
	if (in_file == NULL) {
		puts("[ERROR READING INSTRUCTION FILE]");
		return ferror(in_file);
	}
	read_instructions(in_file, aero.mailboxes, 100);
	while (1)
		run(&aero);
	return 0;
}
