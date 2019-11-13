#include <iostream>
#include <algorithm>
#include <vector>
			  
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> a;
	for (int i = 0; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		a.push_back({x,INT32_MIN});
		a.push_back({y,INT32_MAX });
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		a.push_back({x,i});
	}
	sort(a.begin(),a.end());
	int cn=0;
	vector<int> ans(m);
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].second==INT32_MIN)
			cn++;
		else if (a[i].second == INT32_MAX)
			cn--;
		else
		{
			ans[a[i].second] = cn;
		}
	}
	for (auto i:ans)
		cout << i << ' ';
}