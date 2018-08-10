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
#include <iostream>
#include <vector>

int n, t, ans;
std::vector<int> a;

int main()
{
    int i, x, s;
    cin >> n >> t;

    for (i=0; i<n; ++i)
    {
        cin >> x >> s;
        x=-(x+s*t);
        if (a.empty() || x>=a.back()) a.push_back(x);
        else *std::upper_bound(a.begin(), a.end(), x)=x;
    }

    cout << a.size() << '\n';
    return 0;
}
