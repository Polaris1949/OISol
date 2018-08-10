#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int l, m, i, j, x, y, t=0;
	scanf("%d%d", &l, &m);
	bool a[l+1];
	memset(a, true, sizeof(a));
	
	for (i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		
		for (j=x; j<=y; j++) a[j]=false;
	}
	
	for (i=0; i<=l; i++)
		if (a[i]) t++;
	
	printf("%d\n", t);
	return 0;
}
