#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_BUFF 1000000


int main() {

	long T, N;
	vector<bool> primes(MAX_BUFF + 1, true);
	vector<long> sum(MAX_BUFF + 1, 0);

	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i * i <= MAX_BUFF; i++) {
		if (primes[i]) {
			for (int j = i * i; j <= MAX_BUFF; j += i) {
				primes[j] = false;
			}
		}
	}

	sum[0] = 0;
	sum[1] = 0;
	for (int i = 2; i <= MAX_BUFF; i++) {
		if (primes[i]) {
			sum[i] = sum[i - 1] + i;
		}
		else {
			sum[i] = sum[i - 1];
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << sum[N];
		if (i < T - 1) {
			cout << "\n";
		}
	}

	return 0;
}
