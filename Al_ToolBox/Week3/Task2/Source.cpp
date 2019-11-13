#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define vec vector

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
	double value = 0.0;

	vec<pair<double, int>> arr(weights.size());
	for (int i = 0; i < arr.size(); i++)
		arr[i] = { 1.0*values[i] / weights[i],i };
	sort(arr.rbegin(), arr.rend());

	for (int i = 0; i < arr.size(); i++)
	{
		double w = min(capacity, weights[arr[i].second]);
		value += values[arr[i].second] * ( w / weights[arr[i].second] );
		capacity -= w;
		if (capacity == 0)
			return value;
	}

	return value;
}

int main()
{
	int n;
	int capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++)
		cin >> values[i] >> weights[i];

	double optimal_value = get_optimal_value(capacity, weights, values);

	cout.precision(10);
	cout << optimal_value << endl;
	return 0;
}
