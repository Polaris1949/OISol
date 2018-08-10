#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int n, m, sum=0;
int a[100][100];
queue<pair<int, int> > q;

void bfs(int x, int y)
{
	q.push(make_pair(x, y));
	
	pair<int, int> temp;
	while (!q.empty())
	{
		temp=q.front();
		a[temp.first][temp.second]=-1;
		
		if (temp.first-1>=0)
			if (a[temp.first-1][temp.second]>0)
				q.push(make_pair(temp.first-1, temp.second));
		if (temp.first+1<n)
			if (a[temp.first+1][temp.second]>0)
				q.push(make_pair(temp.first+1, temp.second));
		if (temp.second-1>=0)
			if (a[temp.first][temp.second-1]>0)
				q.push(make_pair(temp.first, temp.second-1));
		if (temp.second+1<m)
			if (a[temp.first][temp.second+1]>0)
				q.push(make_pair(temp.first, temp.second+1));
		
		q.pop();
	}
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	
	for (i=0; i<n; ++i)
	{
		scanf("\n");
		for (j=0; j<m; ++j)
		{
			scanf("%c", &a[i][j]);
			a[i][j]-='0';
		}
	}
	
	for (i=0; i<n; ++i)
		for (j=0; j<m; ++j)
			if (a[i][j]>0)
			{
				++sum;
				bfs(i, j);
			}
	
	printf("%d\n", sum);
	return 0;
}

/* data:
4 10
0234500067
1034560500
2045600671
0000000089
*/
