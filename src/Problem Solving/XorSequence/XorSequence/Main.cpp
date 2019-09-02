#include <Windows.h>
#include <stdio.h>

#define MAX	50

long arr[MAX];

long getValueFromIndex(int index) {
	if (index % 4 == 0) {
		return index;
	} else if (index % 4 == 1) {
		return 1;
	} else if (index % 4 == 2) {
		return index + 1;
	}
	return 0;
}

long xorSequence(int l, int r) {
	long res = 0;
	long newLeft;
	long newRight;

	if (r - l < 4) {
		for (long i = l; i <= r; i++) {
			res = res ^ getValueFromIndex(i);
		}
		return res;
	}

	if (l % 4 == 1) {
		res = 1 ^ (l + 1) ^ 0;
		newLeft = l + 3;
	} else if (l % 4 == 2) {
		res = (l + 1) ^ 0;
		newLeft = l + 2;
	} else if (l % 4 == 3) {
		res = res ^ 0;
		newLeft = l + 1;
	} else {
		newLeft = l;
	}

	if (r % 4 == 0) {
		res = res ^ r;
		newRight = r - 1;
	} else if (r % 4 == 1) {
		res = res ^ 1 ^ r;
		newRight = r - 2;
	} else if (r % 4 == 2) {
		res = res ^ (r + 1) ^ 1 ^ (r - 2);
		newRight = r - 3;
	} else {
		newRight = r;
	}

	if ((((newRight - newLeft + 1) / 4) % 2) == 1) {
		res = res ^ 2;
	}

	return res;
}

void debug() {
	long res = 0;

	for (long i = 0; i < MAX; i++) {
		res = res ^ getValueFromIndex(i);
		printf("{index = %d, value = %d, xorSequence = %d}\n", i, getValueFromIndex(i), res);
	}
}

long getXorSequenceFromIndex(long index) {
	if (index % 8 == 0 || index % 8 == 1) {
		return index;
	} else if (index % 8 == 2 || index % 8 == 3) {
		return 2;
	} else if (index % 8 == 4 || index % 8 == 5) {
		return index + 2;
	}
	return 0;
}

long xorSequence1(long l, long r) {
	return getXorSequenceFromIndex(l - 1) ^ getXorSequenceFromIndex(r);
}

int main() {
	debug();
	//printf("%d\n", xorSequence1(130226563, 341217047));
	return 0;
}