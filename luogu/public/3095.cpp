#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

int n, m, q;
int x[MAXN], y[MAXN], p[MAXN];

void compose(int* r, int* a, int* b)
{
    for (int i = 0; i < n; i++)
        r[i] = a[b[i]];
}

int main()
{
    int t, i, a;
    cin >> n >> m >> q;
    t = n - m + 1;

    for (i = 0; i < n; ++i)
    {
        x[i] = i;

        if (i < m)
        {
            cin >> a;
            p[--a] = i;
        }
        else p[i] = i;
    }

    rotate(p, p + 1, p + n);

    for (i = 31 - __builtin_clz(t); i >= 0; --i)
    {
        compose(y, x, x);
        memcpy(x, y, sizeof(x));

        if (t & 1 << i)
        {
            compose(y, x, p);
            memcpy(x, y, sizeof(x));
        }
    }

    for (i = 0; i < q; i++)
    {
        cin >> a;
        cout << x[(n + m - 1 - a) % n] + 1 << '\n';
    }

    return 0;
}
