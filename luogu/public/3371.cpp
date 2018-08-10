#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
	int v, w;
	
	node(int i=0, int j=0)
		: v(i), w(j)
	{
	}
	
	bool operator > (const node& x) const
	{
		return this->w>x.w;
	}
};

int n, m, s;
vector<bool> v;
vector<int> d;
vector<vector<node> > g;
priority_queue<node, vector<node>, greater<node> > q;

int main()
{
	int i, x, y, w;
	node temp;
	cin >> n >> m >> s;
	--s;
	g.resize(n);
	v.resize(n);
	d.resize(n, 2147483647);
	
	for (i=0; i<m; i++)
	{
		cin >> x >> y >> w;
		g[--x].push_back(node(--y, w));
	}
	
	d[s]=0;
	q.push(node(s, 0));
	
	while (!q.empty())
	{
		temp=q.top(); q.pop(); x=temp.v;
		
		if (v[x]) continue;
		v[x]=true;
		
		for (i=0; i<g[x].size(); i++)
			if (d[x]+g[x][i].w<d[g[x][i].v])
			{
				d[g[x][i].v]=d[x]+g[x][i].w;
				q.push(node(g[x][i].v, d[g[x][i].v]));
			}
	}
	
	for (i=0; i<n; i++)
		cout << d[i] << ' ';
	
	cout << endl;
	return 0;
}
