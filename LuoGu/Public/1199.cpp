#include <cstdio>
#include <cstring>
using namespace std;

int n, a[501][501];

int main() {
	scanf("%d", &n);
	
	int i, j, x;
	for (i=1; i<=n; i++) {
		for (j=i+1; j<=n; j++) {
			scanf("%d", &x);
			a[i][j]=x;
			a[j][i]=x;
		}
	}
	
	int maxa, maxb, t=-1;
	for (i=1; i<=n; i++) {
		maxa=-1; maxb=-1;
		for (j=1; j<=n; j++) {
			if (a[i][j]>maxa) {
				maxb=maxa;
				maxa=a[i][j];
			}
			else if (a[i][j]>maxb) {
				maxb=a[i][j];
			}
		}
		if (maxb>t) t=maxb;
	}
	
	printf("1\n%d\n", t);
	return 0;
}
