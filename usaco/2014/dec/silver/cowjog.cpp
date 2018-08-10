#if LUOGU
#include <iostream>
using std::cin;
using std::cout;
#else
#include <fstream>
std::ifstream fin("cowjog.in");
std::ofstream fout("cowjog.out");
#define cin fin
#define cout fout
#endif
#include <algorithm>
#include <vector>

typedef long long llong;

llong n, t, ans=1;
std::vector<llong> s;

int main()
{
    llong i, x, y, minv;
    cin >> n >> t;

    for (i=0; i<n; ++i)
    {
        cin >> x >> y;
        s.push_back(x+y*t);
    }

    minv=s[n-1];

    for (i=n-1; i>=0; --i)
    {
        if (s[i]<minv) ++ans;
        minv=std::min(minv, s[i]);
    }

    cout << ans << '\n';
    return 0;
}
