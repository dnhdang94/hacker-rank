#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int prims(int n, vector<vector<int>> edges, int start);
int minKey(int n, vector<int>& key, vector<bool>& free);
 
int minKey(int n, vector<int>& key, vector<bool>& free) {
	int min = INT_MAX, idx = 0;

	for (int i = 1; i < n; i++) {
		if (free[i] && key[i] < min) {
			min = key[i];
			idx = i;
		}
	}

	return idx;
}

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
	int sum = 0;
	int m = n + 1;
	vector<int> parent(m, -1);
	vector<int> key(m, INT_MAX);
	vector<bool> free(m, true);
	vector<vector<int>> mat(m, vector<int>(m, -1));

	for (int i = 0; i < edges.size(); i++) {
		mat[edges[i][0]][edges[i][1]] = edges[i][2];
		mat[edges[i][1]][edges[i][0]] = edges[i][2];
	}

	key[start] = 0;

	for (int i = 1; i < m - 1; i++) {
		int u = minKey(m, key, free);
		free[u] = false;
		for (int j = 1; j < m; j++) {
			if (free[j] && mat[u][j] != -1 && mat[u][j] < key[j]) {
				key[j] = mat[u][j];
				parent[j] = u;
			}
		}
	}

	for (int i = 1; i < m; i++) {
		sum += mat[i][(parent[i] != -1) ? parent[i] : i];
	}

	return sum + 1;
}

int main()
{
	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	vector<vector<int>> edges(m);
	for (int i = 0; i < m; i++) {
		edges[i].resize(3);

		for (int j = 0; j < 3; j++) {
			cin >> edges[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int start;
	cin >> start;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int result = prims(n, edges, start);

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