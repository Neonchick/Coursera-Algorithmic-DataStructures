#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
	//write your code here
	vector<bool> a(W + 1, false);
	a[0] = true;
	for (int i = 0; i < w.size(); i++)
		for (int j = W; j >= 0; j--)
			if (a[j] && j + w[i] <= W)
				a[j + w[i]] = true;
	if (a[W] && a[W / 3 * 2] && a[W / 3])
		return 1;
	else return 0;
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> w(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> w[i];
		sum += w[i];
	}
	if (sum % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	std::cout << optimal_weight(sum, w) << endl;
}
