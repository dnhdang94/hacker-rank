#include <bits/stdc++.h>

using namespace std;

#define MAX_RANGE		100

typedef struct _PAIR {
	int n;
	string s;
} PAIR, *PPAIR;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);
void countSort(vector<vector<string>> arr);

// Complete the countSort function below.
void countSort(vector<vector<string>> arr) {
	vector<PAIR> v, output(arr.size());
	vector<int> count(MAX_RANGE, 0);

	for (int i = 0; i < arr.size(); i++) {
		PAIR p;
		p.n = atoi(arr[i][0].c_str());
		if (i < (arr.size() / 2)) {
			p.s = "-";
		}
		else {
			p.s = arr[i][1];
		}
		v.push_back(p);
	}

	for (int i = 0; i < v.size(); i++) {
		count[v[i].n]++;
	}

	for (int i = 1; i < MAX_RANGE; i++) {
		count[i] += count[i - 1];
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		output[count[v[i].n] - 1].n = v[i].n;
		output[count[v[i].n] - 1].s = v[i].s;
		count[v[i].n]--;
	}

	for (int i = 0; i < output.size(); i++) {
		cout << output[i].s;
		if (i < output.size() - 1) {
			cout << " ";
		}
	}
}

int main() {

	ifstream iFile;
	iFile.open("test.txt");

	string n_temp;
	getline(iFile, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<vector<string>> arr(n);

	for (int i = 0; i < n; i++) {
		arr[i].resize(2);

		string arr_row_temp_temp;
		getline(iFile, arr_row_temp_temp);

		vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

		for (int j = 0; j < 2; j++) {
			string arr_row_item = arr_row_temp[j];

			arr[i][j] = arr_row_item;
		}
	}

	countSort(arr);

	iFile.close();

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string& str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
