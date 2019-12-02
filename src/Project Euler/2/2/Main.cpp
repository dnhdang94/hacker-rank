#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


unsigned long long int Fibo(unsigned long long n);


unsigned long long int Fibo(unsigned long long n)
{
	unsigned long long int sum = 2, a0 = 1, a1 = 2, tmp = 0;

	for (;;)
	{
		tmp = a0 + a1;
		if (tmp > n) 
		{
			break;
		}
		a0 = a1;
		a1 = tmp;

		if ((tmp & 1) == 0)
		{
			sum += tmp;
		}
	}

	return sum;
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		long n;
		cin >> n;
		cout << Fibo(n) << endl;
	}
	return 0;
}
