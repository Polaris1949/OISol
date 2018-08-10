#include <iostream>
#define MOD 6662333
using namespace std;

typedef long long llong;

int powmod(int n, llong m)
{
    int ret=1;

    while (m)
    {
        if (m&1) ret=llong(ret)*n%MOD;
        m>>=1;
        n=llong(n)*n%MOD;
    }

    return ret;
}

int main()
{
    llong n;
    cin >> n;
    cout << powmod(2, n-1) << endl;
    return 0;
}
