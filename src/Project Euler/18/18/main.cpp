#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int max(int a, int b);


int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {

	int T, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<vector<int>> V(102, vector<int>(102, -100));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> V[i][j];
			}
		}

		for (int i = N; i >= 2; i--) {
			for (int j = 1; j <= i; j++) {
				V[i - 1][j] = V[i - 1][j] + max(V[i][j], V[i][j + 1]);
			}
		}

		cout << V[1][1] << "\n";
	}

	return 0;
}
