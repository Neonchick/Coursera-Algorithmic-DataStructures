#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_change(int m)
{
	vector<int> a(m + 5, INT32_MAX);
	a[0] = 0;
	vector<int> b = { 1,3,4 };
	for (int j = 0; j < 3; j++)
		for (int q = b[j]; q <= m; q += b[j])
			for (int i = m - 1; i >= 0; i--)
				if (i + b[j] <= m && a[i] != INT32_MAX)
					a[i + b[j]] = min(a[i + b[j]], a[i] + 1);
	return a[m];
}

int main()
{
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
