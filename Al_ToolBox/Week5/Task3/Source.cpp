#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2)
{
	vector<vector<int>> a(str1.size() + 1, vector<int>(str2.size() + 1));
	a[0][0] = 0;
	for (int i = 1; i < str1.size() + 1; i++)
		a[i][0] = a[i - 1][0] + 1;
	for (int i = 1; i < str2.size() + 1; i++)
		a[0][i] = a[0][i - 1] + 1;
	for (int i = 1; i < str1.size() + 1; i++)
		for (int j = 1; j < str2.size() + 1; j++)
		{
			a[i][j] = a[i][j - 1] + 1;
			a[i][j] = min(a[i][j], a[i - 1][j] + 1);
			if (str1[i - 1] == str2[j - 1])
				a[i][j] = min(a[i][j], a[i - 1][j - 1]);
			else a[i][j] = min(a[i][j], a[i - 1][j - 1] + 1);
		}
	return a[str1.size()][str2.size()];
}

int main()
{
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
