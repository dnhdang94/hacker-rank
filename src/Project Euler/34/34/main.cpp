#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int calDigitsFactSum(int N);
int sumValidNumbers(int N);

int g_digitFactorial[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };


int calDigitsFactSum(int N) {

	int sum = 0;

	while (N > 0) {
		int digit = N % 10;
		sum += g_digitFactorial[digit];
		N /= 10;
	}

	return sum;
}

int sumValidNumbers(int N) {

	int sum = 0;
	int tmp;

	for (int i = 10; i < N; i++) {
		tmp = calDigitsFactSum(i);
		if (tmp % i == 0) {
			sum += i;
		}
	}

	return sum;
}

int main() {

	int N;

	cin >> N;
	cout << sumValidNumbers(N);

	return 0;
}
