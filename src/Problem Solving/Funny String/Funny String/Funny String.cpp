#include <bits/stdc++.h>

using namespace std;

string funnyString(string s);
vector<int> calAbsDiff(string s);

// Complete the funnyString function below.
string funnyString(string s) {
	string r(s);
	vector<int> v1, v2;

	reverse(r.begin(), r.end());
	v1 = calAbsDiff(s);
	v2 = calAbsDiff(r);
	if (v1 == v2) {
		return "Funny";
	}

	return "Not Funny";
}

vector<int> calAbsDiff(string s) {
	vector<int> v;

	for (int i = 0; i < s.length() - 1; i++) {
		v.push_back(abs(s[i] - s[i + 1]));
	}

	return v;
}

int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		getline(cin, s);

		string result = funnyString(s);

		cout << result << "\n";
	}

	return 0;
}
