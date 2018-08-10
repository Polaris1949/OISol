#include <cmath>
#include <cstdio>
using namespace std;

bool a[30][30];
long long f[30][30];

int main() {
	int n, m, x, y, i, j;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	n++; m++; x++; y++; f[0][1]=1;
	
	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			if ((abs(i-x)+abs(j-y)==3)&&(i!=x)&&(j!=y)||\
			(i==x&&j==y)) continue;
			else f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	
	printf("%lld\n", f[n][m]);
	return 0;
}
