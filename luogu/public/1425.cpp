#include <cstdio>

int main() {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	e=c-a; f=d-b;
	if (f<0) {
		e--; f+=60;
	}
	printf("%d %d\n", e, f);
	return 0;
}
