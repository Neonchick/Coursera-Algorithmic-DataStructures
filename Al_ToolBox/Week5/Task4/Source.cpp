#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(vector<int> &a, vector<int> &b, vector<int> &c)
{
	vector<vector<vector<int>>> m(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1)));
	for (int i = 1; i < a.size() + 1; i++)
		for (int j = 1; j < b.size() + 1; j++)
			for (int k = 1; k < c.size() + 1; k++)
			{
				m[i][j][k] = m[i][j][k - 1];
				m[i][j][k] = max(m[i][j][k], m[i][j - 1][k]);
				m[i][j][k] = max(m[i][j][k], m[i - 1][j][k]);
				m[i][j][k] = max(m[i][j][k], m[i - 1][j - 1][k]);
				m[i][j][k] = max(m[i][j][k], m[i - 1][j][k - 1]);
				m[i][j][k] = max(m[i][j][k], m[i][j - 1][k - 1]);
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
					m[i][j][k] = max(m[i][j][k], m[i - 1][j - 1][k-1] + 1);
				else m[i][j][k] = max(m[i][j][k], m[i - 1][j - 1][k-1]);
			}
	return m[a.size()][b.size()][c.size()];
}

int main()
{
	int n, m, k;
	cin >> n;
	vector<int> str1(n);
	for (int i = 0; i < n; i++)
		cin >> str1[i];
	cin >> m;
	vector<int> str2(m);
	for (int i = 0; i < m; i++)
		cin >> str2[i];
	cin >> k;
	vector<int> c(k);
	for (int i = 0; i < k; i++)
		cin >> c[i];
	std::cout << edit_distance(str1, str2, c) << std::endl;
	return 0;
}
