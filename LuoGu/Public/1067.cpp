#include <cstdio>
using namespace std;

int n, a[101];

int main() {
	scanf("%d", &n);
	
	int i;
	for (i=n; i>=1; i--) {
		scanf("%d", &a[i]);
		if (!a[i]) continue;
		else if (a[i]>0) {
			if (i!=n) printf("+");
			if (a[i]>1) printf("%d", a[i]);
			printf("x");
			if (i>1) printf("^%d", i);
		}
		else {
			if (a[i]<-1) printf("%d", a[i]);
			else printf("-");
			printf("x");
			if (i>1) printf("^%d", i);
		}
	}
	
	scanf("%d", &a[0]);
	if (a[0]) {
		if (a[0]>0) printf("+");
		printf("%d", a[0]);
	}
	
	printf("\n");
	return 0;
}
