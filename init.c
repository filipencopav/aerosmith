#include "stdio.h"
#include "init.h"

void read_instructions(FILE *in_file, int mailboxes[], size_t mailboxes_len) {
	size_t i;
	for (i = 0; i < mailboxes_len; i++)
		if (fscanf(in_file, " %d ", mailboxes + i) == EOF)
			break;
}
