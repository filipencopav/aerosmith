#include <stdio.h>
#include <stddef.h>
#include "aero.h"
#include "util.h"
#include "instr.h"
#include "init.h"

void (*instructions[10])(size_t, Aerosmith *) = {
	cob,
	add,
	sub,
	empty,
	empty,
	lda,
	bra,
	brz,
	brp,
	io,
};

void run(Aerosmith *aero) {
	size_t addr = digits_at(aero->mailboxes[aero->program_counter], 2, 1);
	size_t instr = digit_at(aero->mailboxes[aero->program_counter], 3);
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
