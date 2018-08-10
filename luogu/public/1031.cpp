#include <cstdio>
using namespace std;

int n, a[101], s=0, avg=0, m=0;

int main() {
	int i;
	scanf("%d", &n);
	
	for (i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		avg+=a[i];
	}
	avg/=n;
	
	for (i=1; i<=n; i++) {
		a[i]-=avg;
		s+=a[i];
		if (s!=0) m++;
	}
	
	printf("%d\n", m);
	return 0;
}
