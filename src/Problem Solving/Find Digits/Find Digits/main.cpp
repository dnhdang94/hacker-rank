#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {

	int number = n;
	int count = 0;

	while (number > 0) {
		int d = number % 10;
		if (d != 0 && n % d == 0) {
			count++;
		}

		number /= 10;
	}

	return count;
}

int main()
{
	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int result = findDigits(n);

		cout << result << "\n";
	}

	return 0;
}
