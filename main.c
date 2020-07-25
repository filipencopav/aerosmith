#include <stdio.h>
#include <stddef.h>
#include <errno.h>

int accumulator;
int mailboxes[100] = { 0 };
int program_counter = 0;

#include "util.c"
#include "instr.c"
#include "init.c"

int execute(int instr) {
	size_t addr = num_on_pos(instr, 2, 1);
	program_counter++;
	switch (digit_at(instr, 2)) {
		default:
			fprintf(stderr, "[INVALID INSTRUCTION]: %d", instr);
			return 1;
		case 0:
			fprintf(stdout, "[COFFEE BREAK]\n");
			return 1;
		case 1:
			add(addr);
			break;
		case 2:
			sub(addr);
			break;
		case 3:
			sta(addr);
			break;
		case 5:
			lda(addr);
			break;
		case 6:
			bra(addr);
			break;
		case 7:
			brz(addr);
			break;
		case 8:
			brp(addr);
			break;
		case 9:
			if (instr == 901)
				inp();
			else if (instr == 902)
				out();
			break;
	}
	return 0;
}

int main() {
	FILE *in_file = fopen("instr.txt", "r");
	if (in_file == NULL) {
		puts("[ERROR READING INSTRUCTION FILE]");
		return errno;
	}
	read_instructions(in_file);
	while (mailboxes[program_counter] != 0)
		execute(mailboxes[program_counter]);
	fprintf(stdout, "[COB]\n");
	return 0;
}
