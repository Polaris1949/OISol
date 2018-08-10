#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge
{
	int v, w;
	
	edge(int i=0, int j=0)
		: v(i), w(j)
	{
	}
};

int n, p, c, ans=2147483647;
vector<vector<edge> > g;
vector<int> cow, d;
vector<bool> inq;
queue<int> q;

void spfa(int s)
{
	int i, x, y, w;
	d=vector<int>(p, 2147483647);
	inq=vector<bool>(p);
	q.push(s);
	inq[s]=true;
	d[s]=0;
	
	while (!q.empty())
	{
		x=q.front(); q.pop();
		inq[x]=false;
		
		for (i=0; i<g[x].size(); i++)
		{
			y=g[x][i].v;
			w=g[x][i].w;
			
			if (d[x]+w<d[y])
			{
				d[y]=d[x]+w;
				
				if (!inq[y])
				{
					q.push(y);
					inq[y]=true;
				}
			}
		}
	}
}

int main()
{
	int i, j, x, y, w;
	cin >> n >> p >> c;
	cow.resize(p);
	g.resize(p);
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		++cow[--x];
	}
	
	for (i=0; i<c; i++)
	{
		cin >> x >> y >> w;
		--x; --y;
		g[x].push_back(edge(y, w));
		g[y].push_back(edge(x, w));
	}
	
	for (i=0; i<p; i++)
	{
		spfa(i);
		x=0;
		
		for (j=0; j<p; j++)
			if (i!=j) x+=cow[j]*d[j];
		
		ans=min(ans, x);
	}
	
	cout << ans << endl;
	return 0;
}
