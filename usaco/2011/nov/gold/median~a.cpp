#include <cstdio>

using namespace std;
#define MAXN 100005

int n, x, a[MAXN], b[2 * MAXN], s;
long long total;

FILE *in = fopen("median.in", "r"), *out = fopen("median.out", "w");

int query(int p) {
    int t = 0;
    for (int i=(p + MAXN); i; i -= (i & -i)) {
	t += b[i];
    }
    return t;
}
void update(int p) {
    for (int i=(p + MAXN); i < 2*MAXN; i += (i & -i)) {
	b[i]++;
    }
}

int main() {
    fscanf(in, "%d%d", &n, &x);
    for (int i=0; i<n; ++i) {
	fscanf(in, "%d", &a[i]);
	a[i] = (a[i] >= x ? 1 : -1);
    }
    update(0);

    for (int i=0; i<n; ++i) {
	s += a[i];
	total += query(s);
	update(s);
    }
    fprintf(out, "%lld\n", total);

    return 0;
}
