#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int> > pp;
const int INF=100000000;

int n, c;
vector<vector<int>> rect;
vector<pp> edges;
vector<bool> seen;

multiset<pair<int, int> > s;

int main()
{
	int i, j, index, start;
	cin >> n;
	rect.resize(n, vector<int>(4));
	edges.resize(n*2);
	seen.resize(n);

	for (i=0; i<n; ++i)
	{
		for (j=0; j<4; ++j)
			cin >> rect[i][j];

		edges[2*i]=make_pair(rect[i][0], make_pair(i, 1));
		edges[2*i+1]=make_pair(rect[i][2], make_pair(i, 0));
	}

	sort(edges.begin(), edges.end());

	s.insert({INF, 1});

	for (i=0; i<2*n; ++i)
	{
		index = edges[i].second.first;
		start = edges[i].second.second;

		auto p = *(s.lower_bound(make_pair(rect[index][1], -1)));

		if (start)
		{
			if (p.second == 1)
			{
				++c;
				seen[index] = 1;

				s.insert(make_pair(rect[index][1], 1));
				s.insert(make_pair(rect[index][3], 0));
			}
		}
		else
		{
			if (seen[index])
			{
				s.erase(s.find(make_pair(rect[index][1], 1)));
				s.erase(s.find(make_pair(rect[index][3], 0)));
			}
		}
	}

	cout << c << endl;
	return 0;
}

