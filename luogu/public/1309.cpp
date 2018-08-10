#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct swiss {
	int n, s, w;
};

bool comp(swiss a, swiss b) {
	if (a.s!=b.s) return a.s>b.s;
	else return a.n<b.n;
}

int main() {
	int n, r, q, i, j, x, y, u, v, w;
	
	scanf("%d%d%d", &n, &r, &q);
	
	swiss a[2*n+1], win[n+1], lose[n+1];
	
	memset(a, 0, sizeof(a));
	memset(win, 0, sizeof(win));
	memset(lose, 0, sizeof(lose));
	
	for (i=1; i<=2*n; i++) {
		a[i].n=i;
		scanf("%d", &a[i].s);
	}
	
	for (i=1; i<=2*n; i++)
		scanf("%d", &a[i].w);
	
	sort(a+1, a+2*n+1, comp);
	
	for (i=1; i<=r; i++) {
		x=0; y=0;
		
		for (j=1; j<=2*n; j+=2) {
			if (a[j].w>a[j+1].w) {
				a[j].s++;
				win[++x]=a[j];
				lose[++y]=a[j+1];
			}
			else {
				a[j+1].s++;
				win[++x]=a[j+1];
				lose[++y]=a[j];
			}
		}
		
		u=0; v=0; w=0;
		memset(a, 0, sizeof(a));
		
		while (w!=2*n) {
			if (win[++u].s!=lose[++v].s) {
				if (win[u].s>lose[v].s && u<=n) {
					a[++w]=win[u];
					--v;
				}
				else {
					a[++w]=lose[v];
					--u;
				}
			}
			else {
				if (win[u].n<lose[v].n && u<=n) {
					a[++w]=win[u];
					--v;
				}
				else {
					a[++w]=lose[v];
					--u;
				}
			}
		}
		
		memset(win, 0, sizeof(win));
		memset(lose, 0, sizeof(lose));
	}
	
	printf("%d\n", a[q].n);
	return 0;
}
