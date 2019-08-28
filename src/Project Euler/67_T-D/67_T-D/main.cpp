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

	int T, N, m;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<vector<int>> V(102, vector<int>(102, -100));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> V[i][j];
			}
		}

		m = -1;
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				V[i][j] = V[i][j] + max(V[i - 1][j], V[i - 1][j - 1]);

			}
		}

		m = -1;
		for (int i = 1; i <= N; i++) {
			if (m < V[N][i]) {
				m = V[N][i];
			}
		}
		cout << m << "\n";
	}

	return 0;
}
