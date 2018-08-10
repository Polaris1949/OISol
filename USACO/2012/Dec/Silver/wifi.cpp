#include <algorithm>
#include <fstream>
#include <iostream>

std::ifstream fin("wifi.in");
std::ofstream fout("wifi.out");

int n;
long long a, b;
long long v[2000];

int main()
{
    int i, u;
    fin >> n >> a >> b;

    for (i=0; i<n; ++i)
        fin >> v[i];

    std::sort(v, v+n);

    long long cnt = 1;
    long long len = 0;

    for (i=0; i<n-1; ++i)
    {
        u=v[i+1]-v[i];
        if (u*b>2*a) ++cnt;
        else len+=u;
    }

    long long tot=cnt*a*2+len*b;

    if (tot%2==0) fout << (tot/2) << '\n';
    else fout << (tot/2) << ".5" << '\n';

    return 0;
}
