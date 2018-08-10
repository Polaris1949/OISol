#include <algorithm>
#include <cstdio>
using namespace std;

int n, m;
struct p {
	int k, s;
} a[5001];

bool comp(p x, p y) {
	if (x.s!=y.s) return x.s>y.s;
	else return x.k<y.k;
}

int main() {
	scanf("%d%d", &n, &m);
	
	int i, j, x=1.5*m;
	for (i=1; i<=n; i++) {
		scanf("%d%d", &a[i].k, &a[i].s);
	}
	
	sort(a+1, a+n+1, comp);
	printf("%d ", a[x].s);
	
	for (j=x; j<=n; j++) {
		if (a[j].s!=a[x].s) break;
	}
	printf("%d\n", --j);
	
	for (i=1; i<=j; i++) {
		printf("%d %d\n", a[i].k, a[i].s);
	}
	
	return 0;
}
