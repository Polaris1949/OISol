#include <iostream>
#define INF 1000000000
using namespace std;

int n, m, k, q, c, g[201][201];
long long sum;

int main()
{
    int i, j, x, u, v, d, cost;
    cin >> n >> m >> k >> q;

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j)
            if (i!=j) g[i][j]=INF;

    for (i=0; i<m; ++i)
    {
        cin >> u >> v >> d;
        g[--u][--v]=d;
    }

    for (x=0; x<n; ++x)
        for (i=0; i<n; ++i)
            for (j=0; j<n; ++j)
                g[i][j]=min(g[i][j], g[i][x]+g[x][j]);

    for (i=0; i<q; ++i)
    {
        cin >> u >> v;
        cost=INF;

        for (j=0; j<k; ++j)
            cost=min(cost, g[u-1][j]+g[j][v-1]);

        if (cost!=INF)
        {
            ++c;
            sum+=cost;
        }
    }

    cout << c << '\n' << sum << '\n';
    return 0;
}
