#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, x, y, r;
vector<pair<int, int> > e;
set<int> s, a;

int main()
{
	int i, j;
	cin >> n;

	for (i=0; i<n; i++)
	{
		cin >> x >> y >> r;
		x*=-r;
		e.push_back(make_pair(x-r, y));
		e.push_back(make_pair(x, -y));
	}

	sort(e.begin(), e.end());

	for (i=0; i<e.size(); i=j)
	{
		for (j=i; j<e.size() && e[i].first==e[j].first; j++)
		{
			y=e[j].second;
			if (y>0) a.insert(y);
			else a.erase(-y);
		}

		if (!a.empty()) s.insert(*a.begin());
	}

	cout << s.size() << endl;
	return 0;
}
