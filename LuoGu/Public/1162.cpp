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

int n, a[30][30];
queue<p> q;

void bfs()
{
	p temp;
	
	while (!q.empty())
	{
		temp=q.front(); q.pop();
		
		if (temp.x<0 || temp.x>=n || temp.y<0 || temp.y>=n) continue;
		if (a[temp.x][temp.y]!=0) continue;
		a[temp.x][temp.y]=2;
		
		if (a[temp.x-1][temp.y]==0) q.push(p(temp.x-1, temp.y));
		if (a[temp.x+1][temp.y]==0) q.push(p(temp.x+1, temp.y));
		if (a[temp.x][temp.y-1]==0) q.push(p(temp.x, temp.y-1));
		if (a[temp.x][temp.y+1]==0) q.push(p(temp.x, temp.y-1));
	}
}

int main()
{
	int i, j;
	cin >> n;
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			cin >> a[i][j];
	
	for (i=0; i<n; i++)
	{
		if (a[i][0]==0)
		{
			q.push(p(i, 0));
			bfs();
		}
		if (a[i][n-1]==0)
		{
			q.push(p(i, n-1));
			bfs();
		}
		if (a[0][i]==0)
		{
			q.push(p(0, i));
			bfs();
		}
		if (a[n-1][i]==0)
		{
			q.push(p(n-1, i));
			bfs();
		}
	}
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j!=0) cout << ' ';
			
			switch (a[i][j])
			{
				case 0:
					cout << '2';
					break;
				case 2:
					cout << '0';
					break;
				default:
					cout << '1';
					break;
			}
		}
		
		cout << endl;
	}
	
	return 0;
}
