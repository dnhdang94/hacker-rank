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
	vector<int> v;

	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i * i <= MAX_BUFF; i++) {
		if (primes[i]) {
			for (int j = i * i; j <= MAX_BUFF; j += i) {
				primes[j] = false;
			}
		}
	}

	for (int i = 0; i <= MAX_BUFF; i++) {
		if (primes[i]) {
			v.push_back(i);
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << v[N - 1] << "\n";
	}

	return 0;
}
