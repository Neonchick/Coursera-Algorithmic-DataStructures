#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> &stops, int n)
{
	int curS = 0, coutZ=0;
	while (curS <= n)
	{
		int lastS = curS;
		while (curS <= n && stops[curS + 1] - stops[lastS] <= tank)
			curS++;
		if (lastS == curS)
			return -1;
		if (curS>n)
			return coutZ;
		coutZ++;
	}
}


int main()
{
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n + 2);
	stops[0] = 0;
	stops[n + 1] = d;
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i + 1);

	cout << compute_min_refills(d, m, stops, n) << "\n";

	return 0;
}
