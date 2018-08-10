#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[100000];

int main() {
	int i;
	scanf("%d", &n);
	
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	sort(a, a+n);
	
	for (i=0; i<n; i++)
		if (i==0) printf("%d", a[i]);
		else printf(" %d", a[i]);
	
	printf("\n");
	return 0;
}
