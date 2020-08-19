#include "util.h"

static int power(int base, unsigned n) {
	if (n <= 0)
		return 1;
	int i = 1;
	int res = base;
	for (; i < n; i++) {
		res *= base;
	}
	return res;
}

/* counts from 0 */
int digit_at(int num, int pos) {
	int pos_order = power(10, pos);
	return (num / pos_order) % pos_order;
}

/* inclusive at both ends, counts from 1 */
int digits_at(int num, int from, int until) {
	int i;
	int res = 0;
	for (i = from; i >= until; i--) {
		res = res * 10 + digit_at(num, i - 1);
	}
	return res;
}
