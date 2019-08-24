#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


long findPathSum(const vector<vector<long>>& V);
long min(long x, long y);

long min(long x, long y) {
	return (x < y) ? x : y;
}

long findPathSum(const vector<vector<long>>& V) {

	long sum = 0;
	vector<vector<long>> sumMat(V);
	int size = sumMat[0].size();

	for (int i = 1; i < size; i++) {
		sumMat[0][i] += sumMat[0][i - 1];
	}

	for (int i = 1; i < size; i++) {
		sumMat[i][0] += sumMat[i - 1][0];
	}

	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			sumMat[i][j] += min(sumMat[i][j - 1], sumMat[i - 1][j]);
		}
	}

	return sumMat[size - 1][size - 1];
}

int main() {

	int N, n;
	vector<vector<long>> V;

	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			V[i].push_back(n);
		}
	}

	cout << findPathSum(V);

	return 0;
}
