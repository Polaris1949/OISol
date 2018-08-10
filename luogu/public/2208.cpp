#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define MAX 502
#define DIR(e) (mark[e.y][e.x]%2 ? 1 : -1)

int n, m, mark[MAX][MAX];
string mat[MAX];

struct point
{
	int y,x;
} c, d;

queue<point> q;

point fall(point p, int dir)
{
	for (; ; p.y+=dir)
	{
		if (mat[p.y][p.x]=='D') break;
		if (p.y+dir<0 || p.y+dir>=n) return {-1, -1};
		if (mat[p.y+dir][p.x]=='#') break;
	}
	
	return p;
}

point action(point p, int k, int dir)
{
	if (k)
	{
		p.x+=k;
		if (p.x<0 || p.x>=m || mat[p.y][p.x]=='#') return {-1, -1};
	}
	else dir=-dir;
	
	return fall(p, dir);
}

int dfs(point p, int flip)
{
	if (p.y==-1 || mark[p.y][p.x]) return 0;
	mark[p.y][p.x]=flip;
	
	if (p.y==d.y && p.x==d.x) return 1;
	q.push(p);
	
	int dir=DIR(p);
	return dfs(action(p, -1, dir), flip) || dfs(action(p, 1, dir), flip);
}

int main()
{
	cin >> n >> m;
	
	for (int i=0; i<n; i++)
		cin >> mat[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (mat[i][j]=='C') c=fall({i,j},1);
			else if (mat[i][j]=='D') d={i,j};

	if (!dfs(c,1))
		for (; !q.empty(); )
		{
			point e=q.front();
			q.pop();
			point p=action(e, 0, DIR(e));
			if (dfs(p, mark[e.y][e.x]+1)) break;
		}

	cout << mark[d.y][d.x]-1 << endl;
	return 0;
}
