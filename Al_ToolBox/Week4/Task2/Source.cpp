#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

void randomized_quick_sort(vector<int> &a, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int k = a[l + rand() % ( r - l )];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < k && i <= j)
			i++;
		while (a[j] > k &&i <= j)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	
	randomized_quick_sort(a, l, j);
	randomized_quick_sort(a, i , r);
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (int i = 0; i < a.size(); ++i)
	{
		cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << ' ';
	}
}
