#include <cstdio>
using namespace std;

int l, r;

int main() {
	scanf("%d%d", &l, &r);
	
	int i, t, s=0;
	for (i=l; i<=r; i++) {
		t=i;
		while (t>0) {
			if (t%10==2) s++;
			t/=10;
		}
	}
	
	printf("%d\n", s);
	return 0;
}
