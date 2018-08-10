#include <cstdio>
using namespace std;

int n, m, a[101];

int main() {
	scanf("%d%d", &n, &m);
	
	int i, j, x, w=1;
	for (i=1; i<=m; i++) {
		scanf("%d", &a[i]);
	}
	
	for (i=m+1; i<=n; i++) {
		scanf("%d", &x);
		for (j=1; j<=m; j++) {
			if (a[j]<a[w]) w=j;
		}
		a[w]+=x;
	}
	
	w=0;
	for (i=1; i<=m; i++) {
		if (a[i]>w) w=a[i];
	}
	
	printf("%d\n", w);
	return 0;
}
