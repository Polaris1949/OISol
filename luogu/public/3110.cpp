#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
#include <queue>
#include <vector>

typedef long long llong;
llong b, e, p, n, m;
std::vector<std::vector<llong> > g;

std::vector<llong> dist(llong s)
{
     std::vector<llong> d;
     std::queue<llong> q;
     d.resize(n, -1);
     q.push(s);
     d[s]=0;

     while (!q.empty())
     {
         llong x=q.front();
         q.pop();

         for (llong i=0; i<(llong)g[x].size(); ++i)
         {
             llong y=g[x][i];

             if (d[y]==-1)
             {
                 d[y]=d[x]+1;
                 q.push(y);
             }
         }
     }

     return d;
}

int main()
{
    llong i, u, v, minv=1<<30;
    cin >> b >> e >> p >> n >> m;
    g.resize(n, std::vector<llong>());

    for (i=0; i<m; ++i)
    {
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<llong> d0=dist(0);
    std::vector<llong> d1=dist(1);
    std::vector<llong> dn=dist(n-1);

    for (i=0; i<n; ++i)
        minv=std::min(minv, d0[i]*b+d1[i]*e+dn[i]*p);

    cout << minv << '\n';
    return 0;
}
