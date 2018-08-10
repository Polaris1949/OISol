#include <cstdio>
using namespace std;

int n, m, sum=0;
int a[100][100];

void dfs(int x, int y)
{
	a[x][y]=-1;
	
	if (x-1>=0) if (a[x-1][y]>0) dfs(x-1, y);
	if (x+1<n)  if (a[x+1][y]>0) dfs(x+1, y);
	if (y-1>=0) if (a[x][y-1]>0) dfs(x, y-1);
	if (y+1<m)  if (a[x][y+1]>0) dfs(x, y+1);
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
				dfs(i, j);
				++sum;
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
