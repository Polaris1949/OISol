#include <cstdio>
using namespace std;

int n, na, nb;
int a[200], b[200];

int main() {
	scanf("%d%d%d", &n, &na, &nb);
	int i, x, y, sa=0, sb=0;
	
	for (i=0; i<na; i++) {
		scanf("%d", &a[i]);
	}
	
	for (i=0; i<nb; i++) {
		scanf("%d", &b[i]);
	}
	
	for (i=0; i<n; i++) {
		x=a[i%na]; y=b[i%nb];
		if (x==y) continue;
		else if ((x==0&&y==2)||(x==0&&y==3)||(x==1&&y==3)||\
		(x==2&&y==4)||(x==3&&y==4)||(x==1&&y==0)||(x==2&&y==1)||\
		(x==3&&y==2)||(x==4&&y==0)||(x==4&&y==1)) sa++;
		else sb++;
	}
	
	printf("%d %d\n", sa, sb);
	return 0;
}
