#include <cstdio>
using namespace std;

int n, m, f[31][31];

int main() {
	scanf("%d%d", &n, &m);
	f[1][0]=1;
	
	int i, j;
	for (j=1; j<=m; j++) {
		for (i=1; i<=n; i++) {
			f[i][j]=f[(i-1+n-1)%n+1][j-1]+f[(i+1-1)%n+1][j-1];
		}
	}
	
	printf("%d\n", f[1][m]);
	return 0;
}
