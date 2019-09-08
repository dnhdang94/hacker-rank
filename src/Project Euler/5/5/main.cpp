#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX        40

const int g_primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

vector<int> p(int n);

vector<int> p(int n) {

	vector<int> v;
	int d = 2;

	while (n > 1) {
		while (n % d == 0) {
			v.push_back(d);
			n /= d;
		}
		d++;
	}

	return v;
}


int main() {

	int T, N;
	vector<vector<int>> v(MAX + 1);
	int size = sizeof(g_primeNumbers) / sizeof(g_primeNumbers[0]);

	v[1].push_back(1);
	for (int i = 2; i <= MAX; i++) {
		v[i] = p(i);
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		int c, max, res = 1;
		vector<int> mp(MAX + 1, 0);
		cin >> N;
		for (int k = 0; k < size; k++) {
			max = 0;
			for (int j = 2; j <= N; j++) {
				c = count(v[j].begin(), v[j].end(), g_primeNumbers[k]);
				if (c > max) {
					max = c;
				}
			}
			res *= (int)pow(g_primeNumbers[k], max);
		}
		cout << res << "\n";
	}

	return 0;
}
