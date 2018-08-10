#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int INF=1<<30;

struct edge
{
	int s, t, d;
} ge[50010];

vector<pair<int, int> > gl[10010];
int n, m, q, father[10010], h[10010], mini[10010][25], up[10010][25];
bool vis[10010];

int cmp(edge a, edge b)
{
	return a.d>b.d;
}

int find_anc(int p)
{
	int i, j=p, tmp;
	
	for (i=p; father[i]!=0; i=father[i]);
	
	while (father[j]>0)
	{
		tmp=father[j];
		father[j]=i;
		j=tmp;
	}
	
	return i;
}

void build_tree(int p)
{
	int i;
	vis[p]=true;
	
	for (i=0; i<gl[p].size(); i++)
		if (!vis[gl[p][i].first])
		{
			mini[gl[p][i].first][0]=gl[p][i].second;
			up[gl[p][i].first][0]=p;
			h[gl[p][i].first]=h[p]+1;
			build_tree(gl[p][i].first);
		}
}

int move(int& p, int depth)
{
	int i, ans=INF;
	
	for (i=20; i>=0; i--)
		if (h[up[p][i]]>=depth)
		{
			ans=min(ans, mini[p][i]);
			p=up[p][i];
		}
	
	return ans;
}

int query(int x, int y)
{
	if (find_anc(x)!=find_anc(y)) return -1;
	
	int i, ans=INF;
	
	if (h[x]!=h[y]) ans=(h[x]>h[y])?move(x, h[y]):move(y, h[x]);
	if (x==y) return ans;
	
	for (i=20; i>=0; i--)
		if (up[x][i]!=up[y][i])
		{
			ans=min(ans, min(mini[x][i], mini[y][i]));
			x=up[x][i];
			y=up[y][i];
		}
	
	ans=min(ans, min(mini[x][0], mini[y][0]));
	return ans;
}

int main()
{
	int i, j, s, t, d, ancs, anct, x, y;
	
	scanf("%d%d", &n, &m);
	
	for (i=1; i<=m; i++)
		scanf("%d%d%d", &ge[i].s, &ge[i].t, &ge[i].d);
	
	sort(ge+1, ge+m+1, cmp);
	
	for (i=1; i<=m; i++)
	{
		s=ge[i].s;
		t=ge[i].t;
		d=ge[i].d;
		
		ancs=find_anc(s);
		anct=find_anc(t);
		
		if (ancs!=anct)
		{
			father[ancs]=anct;
			gl[s].push_back(make_pair(t, d));
			gl[t].push_back(make_pair(s, d));
		}
	}
	
	for (i=1; i<=n; i++)
		if (!vis[i])
		{
			build_tree(i);
			mini[i][0]=INF;
			up[i][0]=i;
		}
	
	for (i=1; i<=20; i++)
		for (j=1; j<=n; j++)
		{
			up[j][i]=up[up[j][i-1]][i-1];
			mini[j][i]=min(mini[j][i-1], mini[up[j][i-1]][i-1]);
		}
	
	scanf("%d", &q);
	
	for (i=1; i<=q; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}
	
	return 0;
}
