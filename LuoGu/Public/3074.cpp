#include <iostream>
#include <vector>
#define MAXN 10005
using namespace std;

int n, m;
long long t[MAXN];
vector<int> d[MAXN];
long long f[MAXN];

long long dfs(int i)
{
    if (f[i] == -1)
    {
        long long s = 0;

        for (int e : d[i])
            s = max(s, dfs(e));

        f[i] = s + t[i];
    }

    return f[i];
}

int main()
{
    int i, a, b;
    long long ans = 0;
    cin >> n >> m;

    for (i = 0; i < n; ++i)
    {
        cin >> t[i];
        f[i] = -1;
    }

    for (i = 0; i < m; ++i)
    {
        cin >> a >> b;
        --a; --b;
        d[b].push_back(a);
    }

    for (i = 0; i < n; ++i)
        ans = max(ans, dfs(i));

    cout << ans << endl;
    return 0;
}
