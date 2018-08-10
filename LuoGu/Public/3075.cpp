#include <cstring>
#include <iostream>
using namespace std;

constexpr int INF = 1<<30;
constexpr int MAXN = 20;

int n, k, ans=INF;
int v[MAXN][MAXN];
int f[MAXN][MAXN], cost[MAXN][MAXN], s[MAXN];

int main()
{
    int i, j, mask, ix, kx, ky, sx;
    cin >> n >> k;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            cin >> v[i][j];

    for (mask = 0; mask < (1<<(n - 1)); ++mask)
    {
        kx = 0;

        for (i = 0; i < n; ++i)
            kx += (mask >> i) & 1;

        if (kx <= k)
        {
            for (i = 0; i < n; ++i)
            {
                memset(s, 0, sizeof(s));

                for (ix = i + 1; ix <= n; ++ix)
                {
                    cost[i][ix] = 0;
                    sx = 0;

                    for (j = 0; j < n; ++j)
                    {
                        s[j] += v[ix - 1][j];
                        sx += s[j];
                        cost[i][ix] = max(cost[i][ix], sx);
                        if ((mask >> j) & 1) sx = 0;
                    }
                }
            }

            for (ky = 0; ky <= n; ++ky)
                for (i = 0; i <= n; ++i)
                    f[ky][i] = INF;

            f[0][0] = 0;

            for (ky = 1; ky <= n && ky <= (k - kx + 1); ++ky)
            {
                for (i = 0; i < n; ++i)
                    for (ix = i + 1; ix <= n; ++ix)
                        f[ky][ix] = min(f[ky][ix],
                            max(f[ky - 1][i], cost[i][ix]));

                ans = min(ans, f[ky][n]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
