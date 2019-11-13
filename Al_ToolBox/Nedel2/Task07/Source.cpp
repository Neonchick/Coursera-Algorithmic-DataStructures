#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main ()
{
	long long n, m = 10, q;
	cin >> n >> q;
	vector<int> a;
	a.push_back (0);
	a.push_back (1);
	set<int> st;
	int i;
	int sum = 0, sum2 = 0;
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
				for (int j = 0; j < n % i; j++)
					sum += a[j];
				sum %= 10;
				for (int j = 0; j <= q % i; j++)
					sum2 += a[j];
				sum2 %= 10;
				break;
			}
			else st.insert (a[a.size () - 2]);
		}
	}
	cout << (10 + sum2 - sum) % 10;
}