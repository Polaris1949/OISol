#include <cstdio>
#include <cstring>
using namespace std;

int m, n, a[50][50];
int f[100][50][50];

int calc(int p, int x1, int x2)
{
	int y1=p-x1, y2=p-x2;
	
	if (x1<0 || x1>=m || x2<0 || x2>=m) return -1;
	if (y1<0 || y1>=n || y2<0 || y2>=n) return -1;
	
	if (p && x1==x2) return -1;
	
	if (f[p][x1][x2]>=0) return f[p][x1][x2];
	
	if (p==(m-1)+(n-1)) return 0;
	
	int i, temp;
	f[p][x1][x2]=0;
	
	for (i=0; i<4; ++i)
	{
		temp=calc(p+1, x1+i%2, x2+i/2);
		if (temp>f[p][x1][x2]) f[p][x1][x2]=temp;
	}
	
	f[p][x1][x2]+=a[x1][y1]+a[x2][y2];
	return f[p][x1][x2];
}

int main()
{
	int i, j;
	scanf("%d%d", &m, &n);
	
	for (i=0; i<m; ++i)
		for (j=0; j<n; ++j)
			scanf("%d", &a[i][j]);
	
	memset(f, 0xff, sizeof(f));
	printf("%d\n", calc(0, 0, 0));
	return 0;
}
