#include <cstdio>
using namespace std;

int n, k, m, s, t;
int c[101];
bool a[101][101];
int ga[101][101];

int main() {
	int i, j, k, u, v, d;
	scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
	
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++) {
			ga[i][j]=100000;
		}
	}
	
	for (i=1; i<=n; i++) {
		scanf("%d", &c[i]);
	}
	
	for (i=1; i<=k; i++) {
		for (j=1; j<=k; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (i=1; i<=m; i++) {
		scanf("%d%d%d", &u, &v, &d);
		if (d<ga[u][v]) {
			if (!a[c[u]][c[v]]) ga[v][u]=d;
			if (!a[c[v]][c[u]]) ga[u][v]=d;
		}
	}
	
	for (k=1; k<=n; k++) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				if (i==j || i==k || j==k) continue;
				if (ga[i][k]+ga[k][j]<ga[i][j])
					ga[i][j]=ga[i][k]+ga[k][j];
			}
		}
	}
	
	if (ga[s][t]==100000) printf("-1\n");
	else printf("%d\n", ga[s][t]);
	
	return 0;
}
