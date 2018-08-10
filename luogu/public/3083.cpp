#include <iostream>
#include <string>
#define MAXN 1000
using namespace std;

int n, m;
long long k;
string s;
int l[MAXN];
int r[MAXN];

pair<int, int> nxt(pair<int, int> v)
{
    return make_pair((s[v.second] == 'L' ? l : r)[v.first], (v.second + 1) % m);
}

int main()
{
    int i;
    string x;
    pair<int, int> s0(0, 0), s1(0, 0);
    cin >> n >> m >> k;
    k *= m;

    for (i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
    }

    for (i = 0; i < m; ++i)
    {
        cin >> x;
        s += x;
    }

    for (; k > 0; --k)
    {
        s0 = nxt(s0);
        s1 = nxt(nxt(s1));

        if (s0 == s1)
        {
            k--;
            break;
        }
    }

    if (k)
    {
        int rho = 1;
        for (s0 = nxt(s0); s0 != s1; ++rho)
            s0 = nxt(s0);
        k %= rho;
    }

    for (; k > 0; --k)
        s0 = nxt(s0);

    cout << s0.first + 1 << endl;
    return 0;
}
