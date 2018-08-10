#include <algorithm>
#include <iostream>
#define MAXN 500
using namespace std;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int n;
int g[MAXN][MAXN];
bool v[MAXN][MAXN];

int dfs(int i, int j, int d)
{
    if (v[i][j]) return 0;
    v[i][j] = true;

    int c = 1, dir;

    for (dir = 0; dir < 4; ++dir)
    {
        int ix = i + dx[dir];
        int jx = j + dy[dir];

        if (ix >= 0 && ix < n && jx >= 0 && jx < n &&
                abs(g[ix][jx] - g[i][j]) <= d)
            c += dfs(ix, jx, d);
    }

    return c;
}

bool check(int d)
{
    int i, j;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            v[i][j] = false;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            if (!v[i][j] && dfs(i, j, d) * 2 >= n*n)
                    return true;

    return false;
}

int main()
{
    int i, j, l = -1, r = 1000000, mid;
    cin >> n;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            cin >> g[i][j];

    while (r > l + 1)
    {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }


    cout << r << endl;
    return 0;
}
