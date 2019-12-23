#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#ifndef LONG_MAX

#define LONG_MAX 0x7fffffff

#endif


long primMST(const vector<vector<long>>& g);
int findIndex(const vector<long>& val, const vector<bool>& free);
long traverse(const vector<int>& p, const vector<vector<long>>& g);


int findIndex(const vector<long>& val, const vector<bool>& free)
{
	int min_val = LONG_MAX, index = -1;

	for (int i = 0; i < free.size(); i++)
	{
		if (free[i] && val[i] < min_val)
		{
			min_val = val[i];
			index = i;
		}
	}

	return index;
}

long traverse(const vector<int>& p, const vector<vector<long>>& g)
{
	long sum = 0;

	for (int i = 1; i < g.size(); i++)
	{
		sum += g[i][p[i]];
	}

	return sum;
}

long primMST(const vector<vector<long>>& g)
{
	long sum = 0;
	vector<int> parent(g.size(), 0);
	vector<long> val(g.size(), 0);
	vector<bool> free(g.size());

	for (int i = 0; i < g.size(); i++)
	{
		val[i] = LONG_MAX;
		free[i] = true;
	}

	val[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < g.size() - 1; i++)
	{
		int u = findIndex(val, free);

		free[u] = false;

		for (int v = 0; v < g.size(); v++)
		{
			if (g[u][v] < LONG_MAX && free[v] && g[u][v] < val[v])
			{
				parent[v] = u;
				val[v] = g[u][v];
			}
		}
	}

	return traverse(parent, g);
}

int main()
{
	int n, m, u, v;
	long t;
	vector<vector<long>> w;

	cin >> n >> m;
	w.resize(n, vector<long>(n, LONG_MAX));
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> t;
		if (t < w[u - 1][v - 1])
		{
			w[u - 1][v - 1] = t;
			w[v - 1][u - 1] = t;
		}
	}

	cout << primMST(w) << endl;

	return 0;
}
