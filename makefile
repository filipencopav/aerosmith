CC = gcc
CFLAGS = -std=c90

main: *.c
	$(CC) $(CFLAGS) main.c -o $@

run: main
	./$^
	rm main
