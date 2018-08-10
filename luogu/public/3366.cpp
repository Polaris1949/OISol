#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int x, y, w;

	edge(int x, int y, int w)
		: x(x), y(y), w(w)
	{
	}

	bool operator < (const edge& o) const
	{
		if (w!=o.w) return w<o.w;
		else return x<o.x;
	}
};

int n, m, ans;
vector<edge> g;
vector<int> p;

int findp(int x)
{
	if (x==p[x]) return x;
	else return p[x]=findp(p[x]);
}

int main()
{
	int i, j, x, y, w;
	cin >> n >> m;

	for (i=0; i<m; ++i)
	{
		cin >> x >> y >> w;
		g.push_back(edge(--x, --y, w));
	}

	sort(g.begin(), g.end());
	p.resize(n);

	for (i=0; i<n; ++i)
		p[i]=i;

	i=0; j=0;

	for (i=0; i<m; ++i)
	{
		if (findp(g[i].x)!=findp(g[i].y))
		{
			ans+=g[i].w;
			p[p[g[i].x]]=g[i].y;
			if (j==n-1) break;
		}
	}

	cout << ans << endl;
	return 0;
}
