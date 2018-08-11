#include <cstdio>
using namespace std;
#define MAXN 100005

int n, x, a, b[2 * MAXN], s = MAXN;
long long total, t;

FILE *in = fopen("median.in", "r"), *out = fopen("median.out", "w");

int main() {
    fscanf(in, "%d %d", &n, &x);
    total = (long long)n*(n+1)/2;
    b[MAXN] = 1;
    for (int j=0; j<n; ++j) {
	fscanf(in, "%d", &a);
	if (a >= x) { s++; t-=b[s]; }
	else        { t+=b[s]; s--; }
	b[s]++;
	total -= t;
    }
    fprintf(out, "%lld\n", total);
    return 0;
}
