#include <fstream>
using namespace std;

ifstream fin("meeting.in");
ofstream fout("meeting.out");

int n, m;
int ga[100][100], gb[100][100];
bool da[100][6666], db[100][6666];

int main()
{
    int i, j, k, a, b, c, d;
    fin >> n >> m;

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j)
        {
            ga[i][j]=-1;
            gb[i][j]=-1;
        }

    da[0][0]=true;
    db[0][0]=true;

    for (i=0; i<m; ++i)
    {
        fin >> a >> b >> c >> d;
        --a; --b;
        ga[a][b]=c;
        gb[a][b]=d;
    }

    for (i=0; i<n; ++i)
        for (j=0; j<6666; ++j)
            if (da[i][j])
                for (k=0; k<n; ++k)
                    if (ga[i][k]!=-1) da[k][j+ga[i][k]]=true;

    for (i=0; i<n; ++i)
        for (j=0; j<6666; ++j)
            if (db[i][j])
                for (k=0; k<n; ++k)
                    if (gb[i][k]!=-1) db[k][j+gb[i][k]]=true;

    for (i=0; i<6666; ++i)
        if (da[n-1][i] && db[n-1][i])
        {
            fout << i << endl;
            return 0;
        }

    fout << "IMPOSSIBLE" << endl;
    return 0;
}
