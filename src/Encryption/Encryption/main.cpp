#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

	string res;
	int len;
	float sqroot;
	int row, col;

	s.erase (remove (s.begin(), s.end(), ' '), s.end());
	len = s.length();
	sqroot = sqrt(len);
	row = floor(sqroot);
	col = ceil(sqroot);

	if (row * col < len) {
		row++;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (i + col * j < len) {
				res += s[i + col * j];
			}
		}
		res += " ";
	}
	res.pop_back();

	return res;
}

int main() {

	string s;
	string result;

	getline(cin, s);
	result = encryption(s);

	cout << result << "\n";

	return 0;
}