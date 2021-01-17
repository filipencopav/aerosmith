typedef struct {
	size_t len;
	char* str;
} Slice;

// Splits the given string (line) into "tokens" which are just null terminated
// and separated strings strings. Input string has to be NULL terminated.
// Example:
// tokenize("ADD 5 2") -> { 'A', 'D', 'D', '\0', '5', '\0', '2', '\0' }
const char* tokenize(char* line);
