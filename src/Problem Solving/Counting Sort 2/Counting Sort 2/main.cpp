#include <bits/stdc++.h>

using namespace std;

#define MAX_RANGE        100

vector<string> split_string(string);
int max(int a, int b);


int max(int a, int b) {
	return (a > b) ? a : b;
}

// Complete the countingSort function below.
vector<int> countingSort(vector<int> arr) {
	vector<int> count(MAX_RANGE, 0);
	vector<int> sortedArr;
	int m = -1;

	for (int i = 0; i < arr.size(); i++) {
		m = max(m, arr[i]);
		count[arr[i]]++;
	}

	for (int j = 0; j <= m; j++) {
		while (count[j]) {
			sortedArr.push_back(j);
			count[j]--;
		}
	}

	return sortedArr;
}

int main() {
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split_string(arr_temp_temp);

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	vector<int> result = countingSort(arr);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << " ";
		}
	}

	cout << "\n";

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
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
