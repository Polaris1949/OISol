#include <cstdio>
using namespace std;

int a[10001], b[10001], g[10001], k[10001];

int main() {
	int n, i, x, y;
	scanf("%d", &n);
	
	for (i=1; i<=n; i++)
		scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
	
	scanf("%d%d",&x,&y);
	
	for (i=n; i>0; i--)
		if (a[i]<=x && b[i]<=y && a[i]+g[i]>=x \
		&& b[i]+k[i]>=y) {
			printf("%d\n", i);
			return 0;
		}
	
	printf("-1\n");
	return 0;
}
