#include <cstdio>
using namespace std;

int main() {
	int i, n, s=0, a[10];
	
	for (i=0; i<10; i++) scanf("%d", &a[i]);
	
	scanf("%d", &n);
	for (i=0; i<10; i++)
		if (a[i]<=n+30) s++;
	
	printf("%d\n", s);
	return 0;
}
