#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct p
{
	int x, y;
	
	p(int __x = 0, int __y = 0)
		: x(__x), y(__y)
	{
	}
};

const int ax[4]={-1, 1, 0, 0}, ay[4]={0, 0, -1, 1};
int n, m;
bool a[1000][1000], v[1000][1000];
int f[1000][1000];
queue<p> q, fq;

int bfs(int x, int y)
{
	if (f[x][y]+1) return f[x][y];
	
	int i, s=0, tx, ty;
	p t;
	q.push(p(x, y));
	fq.push(p(x, y));
	v[x][y]=true;
	
	while (!q.empty())
	{
		t=q.front(); q.pop(); s++;
		
		for (i=0; i<4; i++)
		{
			tx=t.x+ax[i]; ty=t.y+ay[i];
			
			if (tx>=0 && tx<n && ty>=0 && ty<n)
				if (!v[tx][ty] && a[t.x][t.y]^a[tx][ty])
				{
					v[tx][ty]=true;
					q.push(p(tx, ty));
					fq.push(p(tx, ty));
				}
		}
	}
	
	while (!fq.empty())
	{
		t=fq.front(); fq.pop();
		f[t.x][t.y]=s;
	}
	
	return s;
}

int main()
{
	int i, j, x, y;
	char ch;
	memset(f, -1, sizeof(f));
	
	cin >> n >> m;
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
		{
			cin >> ch;
			a[i][j]=(ch=='0'?false:true);
		}
	
	for (i=0; i<m; i++)
	{
		cin >> x >> y;
		cout << bfs(--x, --y) << endl;
	}
	
	return 0;
}
