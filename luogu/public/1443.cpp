#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

struct p
{
	int x, y, c;
	
	p(int __x = 0, int __y = 0, int __c = 0)
		: x(__x), y(__y), c(__c)
	{
	}
};

const int ax[8]={-2, -2, 2, 2, -1, 1, -1, 1},
		  ay[8]={-1, 1, -1, 1, -2, -2, 2, 2};
int n, m, a[400][400];
queue<p> q;

void bfs(int x, int y)
{
	int i, tx, ty;
	p t;
	a[x][y]=0;
	q.push(p(x, y));
	
	while (!q.empty())
	{
		t=q.front(); q.pop();
		
		for (i=0; i<8; i++)
		{
			tx=t.x+ax[i]; ty=t.y+ay[i];
			
			if (tx>=0 && tx<n && ty>=0 && ty<m)
				if (a[tx][ty]==-1)
				{
					a[tx][ty]=t.c+1;
					q.push(p(tx, ty, t.c+1));
				}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m >> i >> j;
	
	memset(a, -1, sizeof(a));
	bfs(--i, --j);
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			cout << setiosflags(ios::left) << setw(5) << a[i][j];
		
		cout << endl;
	}
	
	return 0;
}
