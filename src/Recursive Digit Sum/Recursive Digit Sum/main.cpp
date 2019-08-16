#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n, int k) {

	int sum = 0;
	int a, b;

	for (int i = 0; i < n.length(); i++) {
		sum = sum + (n[i] - '0');
		a = sum / 10;
		b = sum % 10;
		sum = a + b;
	}

	string tmp = to_string(sum * k);
	sum = 0;
	for (int i = 0; i < tmp.length(); i++) {
		sum = sum + (tmp[i] - '0');
		a = sum / 10;
		b = sum % 10;
		sum = a + b;
	}

	return sum;
}

int main()
{
	string nk_temp;
	getline(cin, nk_temp);

	vector<string> nk = split_string(nk_temp);

	string n = nk[0];

	int k = stoi(nk[1]);

	int result = superDigit(n, k);

	cout << result << "\n";

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
