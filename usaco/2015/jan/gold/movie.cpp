#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("movie.in");
ofstream fout("movie.out");

int n, l;
int f[1<<21];
int d[21], c[21], s[21][1010];
int cnt[1<<21], p[1<<21];
int to[20010][21];
int nxt[21][1010];
vector<int> a;

int main()
{
    int i, j, k, pos, ans=-1;
    fin >> n >> l;
    a.push_back(0);

    for (i=0; i<n; ++i)
    {
        fin >> d[i] >> c[i];

        for (j=0; j<c[i]; ++j)
        {
            fin >> s[i][j];
            a.push_back(s[i][j]+d[i]);
        }
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (i=0; i<(int)a.size(); ++i)
        for (j=0; j<n; ++j)
            to[i][j]=upper_bound(s[j], s[j]+c[j], a[i])-s[j]-1;

    for (i=0; i<n; ++i)
        for (j=0; j<c[i]; ++j)
            nxt[i][j]=lower_bound(a.begin(), a.end(), s[i][j]+d[i])-a.begin();

    for (i=0; i<n; ++i)
        p[1<<i]=i;

    for (i=1; i<(1<<n); ++i)
        cnt[i]=cnt[i-(i&-i)]+1;

    for (i=0; i<(1<<n)-1; ++i)
        for (j=((1<<n)-1)^i; j; j-=j&-j)
        {
            k=p[j&-j];
            pos=to[f[i]][k];
            if (pos<0) continue;
            f[i|(1<<k)]=max(f[i|(1<<k)], max(f[i], nxt[k][pos]));
        }

    for (i=0; i<(1<<n); ++i)
        if (a[f[i]]>=l && (ans==-1 || cnt[i]<ans))
            ans=cnt[i];

    fout << ans << endl;
    return 0;
}
