#include <bits/stdc++.h>

using namespace std;

#define MASK 0x800000000

long debug(long x) {
	
	int count = 0;

	for (long i = 1; i < x; i++) {
		if ((x ^ i) > x) {
			count++;
		}
	}

	return count;
}

__int64 theGreatXor(__int64 x) {

	__int64 count = 0;
	__int64 mask = MASK;

	for (;;) {

		if ((mask & x) == 0) {
			mask >>= 1;
			continue;
		}

		while (mask > 0) {
			if ((mask & x) == 0) {
				count ^= mask;
			}
			mask >>= 1;
		}
		break;
	}

	return count;
}


int main() {

	__int64 q;

	cin >> q;
	cout << theGreatXor(q) << endl;
	return 0;
}