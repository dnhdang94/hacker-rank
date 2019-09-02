#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the absolutePermutation function below.
vector<int> absolutePermutation(int n, int k) {

	int size = n + 1;
	vector<int> v(size);
	vector<bool> b(size, false);

	iota(v.begin(), v.end(), 1);
	for (int i = 1; i < size; i++) {

		if ((i - k >= 1) && (b[i - k] == false)) {
			b[i - k] = true;
			v[i] = i - k;
			continue;
		}

		if ((i + k < size) && (b[i + k] == false)) {
			b[i + k] = true;
			v[i] = i + k;
			continue;
		}

		v.clear();
		return v;
	}

	v.erase(v.begin());
	return v;
}

int main()
{
	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string nk_temp;
		getline(cin, nk_temp);

		vector<string> nk = split_string(nk_temp);

		int n = stoi(nk[0]);

		int k = stoi(nk[1]);

		vector<int> result = absolutePermutation(n, k);

		if (result.size() <= 0) {
			cout << -1;
		} else {
			for (int i = 0; i < result.size(); i++) {
				cout << result[i];

				if (i != result.size() - 1) {
					cout << " ";
				}
			}
		}

		cout << "\n";
	}

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
