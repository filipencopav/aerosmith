void read_instructions(FILE *in_file) {
	size_t i;
	for (i = 0; i < 100; i++)
		if (fscanf(in_file, " %d ", mailboxes + i) == EOF)
			break;
}
