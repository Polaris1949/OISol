#include <cstdio>
#include <cstring>
using namespace std;

char s[25];
bool e=false;
int x=1, y=1;
int a[10001], b[10001], c[10001], d[10001];

int main() {
	int i, len;
	
	while (scanf("%s", s)!=EOF && !e) {
		len=strlen(s);
		
		for (i=0; i<len; i++) {
			if (s[i]=='E') {
				e=true; break;
			}
			if (s[i]=='W') {
				a[x]++; c[y]++;
				if (a[x]>=11 && a[x]-b[x]>=2) x++;
				if (c[y]>=21 && c[y]-d[y]>=2) y++;
			}
			if (s[i]=='L') {
				b[x]++; d[y]++;
				if (b[x]>=11 && b[x]-a[x]>=2) x++;
				if (d[y]>=21 && d[y]-c[y]>=2) y++;
			}
		}
	}
	
	for (i=1; i<=x; i++) printf("%d:%d\n", a[i], b[i]);
	printf("\n");
	for (i=1; i<=y; i++) printf("%d:%d\n", c[i], d[i]);
	
	return 0;
}
