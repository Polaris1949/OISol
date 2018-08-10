#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, maxd, ans=1<<16;
vector<vector<int>> g, s;
vector<int> d, f, t;
queue<int> q;

void dfs(int r, int p)
{
	if (p>ans) return;

	if (r>maxd)
	{
		ans=min(ans, p);
		return;
	}

	int temp=0;

	for (int e : s[r])
		if (t[f[e]])
		{
			t[e]=r;
			++temp;
		}

	if (temp==(int)s[r].size())
	{
		ans=min(ans, p);
		return;
	}

	for (int e : s[r])
	{
		if (t[e]) continue;
		t[e]=true;
		dfs(r+1, p+s[r].size()-temp-1);
		t[e]=false;
	}

	for (int i=0; i<n; ++i)
		if (t[i]==r) t[i]=false;
}

int main()
{
	int x, y;
	cin >> n >> m;
	g.resize(n);
	s.resize(n);
	d.resize(n);
	f.resize(n, -1);
	t.resize(n);

	for (int i=0; i<m; ++i)
	{
		cin >> x >> y;
		g[--x].push_back(--y);
		g[y].push_back(x);
	}

	q.push(0);
	s[0].push_back(0);
	d[0]=0;

	while (!q.empty())
	{
		x=q.front();
		q.pop();
		maxd=max(maxd, d[x]);

		for (int e : g[x])
			if (e!=f[x])
			{
				d[e]=d[x]+1;
				f[e]=x;
				s[d[e]].push_back(e);
				q.push(e);
			}
	}

	dfs(1, 1);
	cout << ans << endl;
	return 0;
}
