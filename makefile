CFLAGS = -std=c90 -g

aerosmith: *.c
	$(CC) $(CFLAGS) $^ -o $@

run: aerosmith
	./$^
	rm $^
