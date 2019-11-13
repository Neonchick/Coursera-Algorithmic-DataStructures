#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

vector<int> optimal_sequence(int n)
{
	vector<int> se(n + 1);
	se[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		se[i] = se[i - 1] + 1;
		if (i % 3 == 0)
			se[i] = min(se[i / 3] + 1, se[i]);
		if (i % 2 == 0)
			se[i] = min(se[i / 2] + 1, se[i]);
	}
	return se;
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> se = optimal_sequence(n);
	cout << se[n] << endl;
	vector<int> ans;
	int i = n;
	while (i != 1)
	{
		ans.push_back(i);
		if (i % 3 == 0 && se[i] - 1 == se[i / 3])
		{
			i/=3;
			continue;
		}
		if (i % 2 == 0 && se[i] - 1 == se[i / 2])
		{
			i /= 2;
			continue;
		}
		i--;
	}
	ans.push_back(1);
	for (int i=ans.size()-1; i>=0; i--)
		cout << ans[i] << ' ';
}
