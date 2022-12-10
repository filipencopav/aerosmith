CFLAGS = -std=c99 -g -pedantic

aerosmith: main.c parser.c panic.c tokens.c dynstring.c
	$(CC) $(CFLAGS) $^ -o $@

run: aerosmith
	./$^
	rm $^

test: test.c parser.c panic.c tokens.c dynstring.c
	$(CC) $(CFLAGS) $^ -o $@

run-test: test
	./$^
	rm $^

clean: aerosmith
	rm $^
