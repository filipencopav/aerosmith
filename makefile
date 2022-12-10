CFLAGS = -std=c99 -g -pedantic

aerosmith: main.c src/*.c
	$(CC) $(CFLAGS) $^ -o $@

run: aerosmith
	./$^
	rm $^

test: test.c src/*.c
	$(CC) $(CFLAGS) $^ -o $@

run-test: test
	./$^
	rm $^

clean: aerosmith
	rm $^
