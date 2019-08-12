#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int max(int a, int b) {
	return (a > b) ? a : b;
}

int calculate(int a, int a_10, int a0_1, int a01, int a10) {
	int sum = 0;

	sum = max(0, a - a_10) + max(0, a - a0_1) + max(0, a - a01) + max(0, a - a10);

	return sum;
}

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) 
{
	int totalSurface = 0;

	for (int i = 1; i < A.size() - 1; i++) {
		for (int j = 1; j < A[i].size() - 1; j++) {
			totalSurface += calculate(A[i][j], A[i - 1][j], A[i][j - 1], A[i][j + 1], A[i + 1][j]);
		}
	}

	totalSurface += 2 * ((A.size() - 2) * (A[0].size() - 2));

	return totalSurface;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string HW_temp;
	getline(cin, HW_temp);

	vector<string> HW = split_string(HW_temp);

	int H = stoi(HW[0]);

	int W = stoi(HW[1]);

	vector<vector<int>> A(H + 2);
	A[0].resize(W + 2);
	A[A.size() - 1].resize(W + 2);
	for (int i = 1; i <= H; i++) {
		A[i].resize(W + 2);

		for (int j = 1; j <= W; j++) {
			cin >> A[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = surfaceArea(A);

	fout << result << "\n";

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
