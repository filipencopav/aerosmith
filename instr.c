void add(size_t addr) {
	accumulator += mailboxes[addr];
}

void sub(size_t addr) {
	accumulator -= mailboxes[addr];
}

void sta(size_t addr) {
	mailboxes[addr] = accumulator;
}

void lda(size_t addr) {
	accumulator = mailboxes[addr];
}

void bra(size_t addr) {
	program_counter = addr;
}

void brz(size_t addr) {
	if (accumulator == 0)
		program_counter = addr;
}

void brp(size_t addr) {
	if (accumulator >= 0)
		program_counter = addr;
}

void inp() {
	printf("[INP]: ");
	scanf(" %d", &accumulator);
}

void out() {
	printf("[OUT]: %d\n", accumulator);
}
