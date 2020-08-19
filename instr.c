#include <stdlib.h>
#include <stdio.h>

#include "aero.h"
#include "instr.h"

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
	if (aero->accumulator == 0)
		aero->program_counter = addr;
}

void brp(size_t addr, Aerosmith *aero) {
	if (aero->accumulator >= 0)
		aero->program_counter = addr;
}

void inp(size_t addr, Aerosmith *aero) {
	printf("[INP]: ");
	scanf(" %d", aero->accumulator);
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
