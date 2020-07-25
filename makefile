CFLAGS = -std=c90

main: *.c
	gcc $(CFLAGS) main.c -o $@

run: main
	./$^
