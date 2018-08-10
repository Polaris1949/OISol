#include <iostream>
using namespace std;

long long p[100000], s[100000];

int main()
{
    int n, m, i;
    long long a, b, c, x, y, ans=0;
    cin >> n >> m;

    for (i=0; i<m; ++i)
        cin >> p[i];

    for (i=0; i<m-1; ++i)
    {
        x=max(p[i], p[i+1]);
        y=min(p[i], p[i+1]);
        ++s[y]; --s[x];
    }

    for (i=1; i<n; ++i)
    {
        cin >> a >> b >> c;
        s[i]+=s[i-1];
        ans+=min(a*s[i], b*s[i]+c);
    }

    cout << ans << '\n';
    return 0;
}
