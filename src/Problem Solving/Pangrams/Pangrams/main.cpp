#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
	char pool['z' - 'a' + 1] = { 0 };
	int size = sizeof(pool) / sizeof(pool[0]);

	for (auto a : s) {
		char t = tolower(a);
		if ('a' <= t && t <= 'z') {
			pool[t - 'a'] = 1;
		}
	}

	for (int i = 1; i < size; i++) {
		pool[i] += pool[i - 1];
	}

	if (pool['z' - 'a'] == size) {
		return "pangram";
	}

	return "not pangram";
}

int main()
{
	string s;
	getline(cin, s);

	string result = pangrams(s);

	cout << result << "\n";

	return 0;
}
