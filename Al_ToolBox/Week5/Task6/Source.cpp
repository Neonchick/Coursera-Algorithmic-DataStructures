#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

long long ev(long long a, long long b, char op)
{
	if (op == '*')
	{
		return a * b;
	}
	else if (op == '+')
	{
		return a + b;
	}
	else if (op == '-')
	{
		return a - b;
	}
	else
	{
		assert(0);
	}
}

long long get_maximum_value(const string &exp)
{
	vector<vector<long long>> mx(exp.size() / 2 + 1, vector<long long>(exp.size() / 2 + 1, -9223372036854775807));
	vector<vector<long long>> mn(exp.size() / 2 + 1, vector<long long>(exp.size() / 2 + 1, 9223372036854775807));
	for (long long i = 0; i < exp.size() / 2 + 1; i++)
	{
		mx[i][i] = exp[i * 2] - '0';
		mn[i][i] = exp[i * 2] - '0';
	}

	for (long long j = 1; j < exp.size() / 2 + 1; j++)
	{
		for (long long i = 0; i < exp.size() / 2 + 1 - j; i++)
			for (long long k = 0; k < j; k++)
			{
				mx[i][i + j] = max(mx[i][i + j], ev(mx[i][i + k], mx[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
				mx[i][i + j] = max(mx[i][i + j], ev(mx[i][i + k], mn[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
				mx[i][i + j] = max(mx[i][i + j], ev(mn[i][i + k], mx[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
				mx[i][i + j] = max(mx[i][i + j], ev(mn[i][i + k], mn[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));

				mn[i][i + j] = min(mn[i][i + j], ev(mx[i][i + k], mx[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
				mn[i][i + j] = min(mn[i][i + j], ev(mx[i][i + k], mn[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
				mn[i][i + j] = min(mn[i][i + j], ev(mn[i][i + k], mx[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
				mn[i][i + j] = min(mn[i][i + j], ev(mn[i][i + k], mn[i + k + 1][i + j], exp[( i + k ) * 2 + 1]));
			}
	}
	return mx[0][exp.size() / 2];
}

int main()
{
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}
