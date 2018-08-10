#include <algorithm>
#include <fstream>
#include <string>
#define MAXA 30
#define MAXN 100
using namespace std;

int n, m, npos;
int nw[MAXA];
string w[MAXA][MAXN];
string list[MAXN];

bool duplicate(int pos, string a)
{
    for (int i=0; i<nw[pos]; ++i)
        if (w[pos][i] == a) return true;
    return false;
}

int num(int x, int y)
{
    int total = 1;
    for (int p=x; p<=y; ++p)
        total *= nw[p];
    return total;
}

string kth(int k)
{
    string s;
    for (int p=0; p<npos; p++)
    {
        if (p>0) s = s + " ";
        s = s + w[p][k / num(p+1, npos-1)];
        k = k % num(p+1, npos-1);
    }
    return s;
}

int before(string s)
{
    int total = 0;
    for (int i=0; i<n; i++)
        if (list[i] <= s) total++;
    return total;
}

int main()
{
    ifstream fin("nocow.in");
    fin >> n >> m;
    for (int i=0; i<n; i++)
    {
        string x, a;
        fin >> x >> x >> x >> x >> a;
        int pos = 0;
        list[i] = "";
        while (a != "cow.")
        {
            if (pos > 0) list[i] += " ";
            list[i] += a;
            if (!duplicate(pos, a))
            {
                w[pos][nw[pos]] = a;
                ++nw[pos];
            }
            ++pos;
            fin >> a;
        }
        npos = pos;
    }
    fin.close();

    for (int i=0; i<npos; i++)
        sort(w[i], w[i]+nw[i]);

    int k = m-1;
    while (k - before(kth(k)) < m-1) ++k;

    ofstream fout("nocow.out");
    fout << kth(k) << '\n';
    fout.close();
    return 0;
}
