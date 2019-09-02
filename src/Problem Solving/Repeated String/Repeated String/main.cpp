#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
__int64 repeatedString(string s, __int64 n) {

	__int64 countA = 0;
	__int64 len = s.length();
	__int64 chunksCount = n / len;
	__int64 lastChunkSize = n % len;

	countA = count(s.begin(), s.end(), 'a');
	countA = countA * chunksCount;
	if (lastChunkSize != 0) {
		countA = countA + count(s.begin(), s.begin() + lastChunkSize, 'a');
	}

	return countA;
}

int main()
{
	string s;
	getline(cin, s);

	__int64 n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	long result = repeatedString(s, n);

	cout << result << "\n";

	return 0;
}