#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main ()
{
	long long n, m = 10;
	cin >> n;
	vector<int> a;
	a.push_back (0);
	a.push_back (1);
	set<int> st;
	int i;
	while (true)
	{
		a.push_back ((a[a.size () - 1] + a[a.size () - 2]) % m);
		if (a.back () == 0)
		{
			if (st.find (a[a.size () - 2]) != st.end ())
			{
				i = a.size () - 2;
				while (a[i] != 0)
					i--;
				int sum = 0;
				for (int j = 0; j <= n % i; j++)
					sum += a[j];
				cout << sum % 10;
				break;
			}
			else st.insert (a[a.size () - 2]);
		}
	}
}