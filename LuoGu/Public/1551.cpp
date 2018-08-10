#include <cstdio>
using namespace std;

int n, e, a[5001], p[5001];

void make(int x) {
	p[x]=x;
}

int find(int x) {
	if (x!=p[x]) p[x]=find(p[x]);
	return p[x];
}

void union_set(int x, int y) {
	x=find(x); y=find(y);
	if (x<y) p[y]=x;
	else p[x]=y;
}

int main() {
	int i, x, y, q;
	scanf("%d%d%d", &n, &e, &q);
	
	for (i=1; i<=n; i++) {
		make(i);
	}
	
	for (i=1; i<=e; i++) {
		scanf("%d%d", &x, &y);
		union_set(x, y);
	}
	
	for (i=1; i<=q; i++) {
		scanf("%d%d", &x, &y);
		if (find(x)==find(y)) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
