#include <cstdio>
using namespace std;

int a[101];

int main() {
	int n=0, i;
	
	while (scanf("%d", &a[++n]))
		if (a[n]==0) break;
	
	for (i=n-1; i>=1; i--)
		if (i!=1) printf("%d ", a[i]);
		else printf("%d\n", a[i]);
	
	return 0;
}
