#if LUOGU
#include <iostream>
using std::cin;
using std::cout;
#else
#include <fstream>
std::ifstream fin("guard.in");
std::ofstream fout("guard.out");
#define cin fin
#define cout fout
#endif
#include <algorithm>
#include <vector>
#define INF (1<<30)

struct cow
{
    int h, w, s;
};

int n, h;
std::vector<cow> a;
std::vector<int> f;

int main()
{
    int i, j, cur, ans=-INF;
    cin >> n >> h;
    a.resize(n);
    f.resize(1<<n);

    for (i=0; i<n; ++i)
        cin >> a[i].h >> a[i].w >> a[i].s;

    f[0]=INF;

    for (i=1; i<(1<<n); ++i)
    {
        f[i]=-INF;
        cur=0;

        for (j=0; j<n; ++j)
        {
            if (!(i&(1<<j))) continue;
            f[i]=std::max(f[i], std::min(f[i^(1<<j)]-a[j].w, a[j].s));
            cur+=a[j].h;
        }

        if (cur>=h && f[i]>=0) ans=std::max(ans, f[i]);
    }

    if (ans<0) cout << "Mark is too tall\n";
    else cout << ans << '\n';

    return 0;
}
