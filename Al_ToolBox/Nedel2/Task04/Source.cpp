#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main ()
{
	long long n, m;
	cin >> n >> m;
	vector<int> a;
	a.push_back (0);
	a.push_back (1);
	set<int> st;
	while (true)
	{
		a.push_back((a[a.size() - 1] + a[a.size() - 2]) % m);
		if (a.back() == 0)
		{
			if (st.find (a[a.size() - 2]) != st.end())
			{
				int i=a.size()-2;
				while (a[i]!=0)
					i--;
				cout << a[n%i];
				return 0;
			}
			else st.insert (a[a.size () - 2]);
		}
	}
}