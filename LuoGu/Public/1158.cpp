#include <algorithm>
#include <cstdio>
using namespace std;

int n, xa, ya, xb, yb, ans=1<<30;
struct p {
	int x,y,disa;
} a[100004];
int disb[100004];

bool comp(p a, p b) {
	return a.disa<b.disa;
}

int distance(int ax, int ay, int bx, int by) {
	return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}

int main() {
	int i;
	scanf("%d%d%d%d%d", &xa, &ya, &xb, &yb, &n);
	
	for (i=1; i<=n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].disa=distance(a[i].x, a[i].y, xa, ya);
	}
	
	sort(a+1, a+n+1, comp);
	disb[n]=distance(a[n].x, a[n].y, xb, yb);
	
	for (i=n-1; i>=1; i--) {
		disb[i]=max(disb[i+1], distance(a[i].x, a[i].y, xb, yb));
	}
	
	ans=disb[1];
	
	for (i=1; i<=n; i++) {
		ans=min(ans, a[i].disa+disb[i+1]);
	}
	
	printf("%d\n",ans);
	return 0;
}
