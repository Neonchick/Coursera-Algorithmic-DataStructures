#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

struct Segment
{
	int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
	vector<pair<int, int>> points;
	vector<int> ans;
	//write your code here
	for (int i = 0; i < segments.size(); ++i)
	{
		points.push_back({ segments[i].start,-( i + 1 ) });
		points.push_back({ segments[i].end,( i + 1 ) });
	}
	sort(points.begin(),points.end());
	set<int> st;
	vector<int> cur;
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].second < 0)
			cur.push_back(-points[i].second);
		else
		{
			if (st.find(points[i].second) == st.end())
			{
				ans.push_back(points[i].first);
				for(auto j:cur)
					st.insert(j);
			}
		}
	}
	return ans;
}

int main()
{
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i)
	{
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i)
	{
		std::cout << points[i] << " ";
	}
}
