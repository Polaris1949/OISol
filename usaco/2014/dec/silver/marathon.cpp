#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, k;
int x[500], y[500];
int f[500][500];

int dist(int i, int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int main()
{
	freopen("14.in", "r", stdin);
	int i, j, l, ni, nj;
	scanf("%d%d", &n, &k);
	
	for (i=0; i<n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	
	for (i=0; i<=k; ++i)
		for (j=0; j<n; ++j)
			f[i][j]=1<<30;
	
	for (i=0; i<=k; ++i)
		for (j=0; j<n; ++j)
			for (l=j+1; l<n && i+(l-j-1)<=k; ++l)
			{
				ni=i+(l-j-1); nj=l;
				f[ni][nj]=min(f[ni][nj], f[i][j]+dist(j, l));
			}
	
	printf("%d\n", f[k][n-1]);
	return 0;
}
