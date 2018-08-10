#include <cstdio>
using namespace std;

int main() {
	int i, x, h=0, s=0;
	
	for (i=1; i<=12; i++) {
		h+=300;
		scanf("%d", &x);
		h-=x;
		if (h<0) {
			printf("-%d\n", i);
			return 0;
		}
		else {
			s+=h/100*100;
		}
		h-=h/100*100;
	}
	
	printf("%d\n", s/5*6+h);
	return 0;
}
