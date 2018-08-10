#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > g;
vector<int> ind, a;
vector<bool> vis;
queue<int> q;

int main()
{
	int i, j, s, now, ans=0;
	bool f=false;
	cin >> n >> m;
	ind.resize(n*2);
	vis.resize(n);
	a.resize(n);
	g.resize(n*2);

	for (i=0; i<m; i++)
	{
		cin >> s;

		for (j=0; j<s; j++)
		{
			cin >> a[j];
			a[j]--;
			vis[a[j]]=true;
		}

		for (j=a[0]; j<=a[s-1]; j++)
		{
			if (vis[j])
			{
				g[j].push_back(i+n);
				ind[i+n]++;
				vis[j]=false;
			}
			else
			{
				g[i+n].push_back(j);
				ind[j]++;
			}
		}
	}

	for (i=0; i<n; i++)
		if (!ind[i])
			q.push(i);

	while(!q.empty())
	{
		now=q.front();
		q.pop();

		if (now<n && !f)
		{
			f=true;
			ans++;
		}

		if (now>=n && f)
			f=false;

		for (i=0; i<g[now].size(); i++)
		{
			ind[g[now][i]]--;
			if (!ind[g[now][i]]) q.push(g[now][i]);
		}
	}

	cout << ans << endl;
	return 0;
}
