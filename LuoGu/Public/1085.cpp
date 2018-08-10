#include <cstdio>
using namespace std;

int main() {
	int i, x, y, maxv=0, pos=0;
	
	for (i=1; i<=7; i++) {
		scanf("%d%d", &x, &y);
		if (x+y>8&&x+y!=maxv) {
			maxv=x+y;
			pos=i;
		}
	}
	
	printf("%d\n", pos);
	return 0;
}
