#include <iostream>
#include <vector>

using namespace std;

long long bp(vector<int> &a, int x)
{
	int l = 0, r = a.size() - 1;
	while (l < r - 1)
	{
		int m = ( l + r ) / 2;
		if (a[m] < x)
			l = m;
		else r = m;
	}
	if (a[r] < x)
		return r;
	if (a[l] < x)
		return l;
	return l-1;
}

int fn(vector<int> &a)
{
	if (a.size() == 1)
		return 0;
	vector<int> b(a.size() / 2);
	vector<int> c(a.size() - a.size() / 2);
	for (int i = 0; i < a.size() / 2; i++)
		b[i] = a[i];
	for (int i = 0; i < a.size() - a.size() / 2; i++)
		c[i] = a[i + a.size()/2];
	int ans = fn(b);
	ans += fn(c);
	for (auto i : b)
		ans += bp(c, i)+1;
	b.push_back(INT32_MAX);
	c.push_back(INT32_MAX);
	int q = 0, k = 0;
	for (int i = 0; i < a.size(); i++)
		if (b[q] < c[k])
		{
			a[i] = b[q];
			q++;
		}
		else
		{
			a[i] = c[k];
			k++;
		}
	return ans;
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	vector<int> b(a.size());
	for (size_t i = 0; i < a.size(); i++)
		cin >> a[i];
	cout << fn(a);
}
