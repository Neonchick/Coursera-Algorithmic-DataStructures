#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x;
		y = x;
		while (y<1000)
			y=y*10+x%10;
		a[i]={y,-x};
	}
	sort(a.begin(),a.end(),[](pair<int, int> a, pair<int, int> b) {return to_string(-a.second)+ to_string(-b.second)> to_string(-b.second) + to_string(-a.second);});
	for (int i=0;i<n;i++)
		cout << -a[i].second;
}