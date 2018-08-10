#include <iostream>
using namespace std;

int tot, n, f[100][600];

void dfs(int root)
{
    int i, time, pic;
    cin >> time >> pic;
    time*=2;
    
    if (!pic)
	{
        int lc=++n, rc=++n;
        dfs(lc);
        dfs(rc);
        
        for (i=time; i<tot; ++i)
            for (int j=0; j<=i-time; ++j)
                f[root][i]=max(f[root][i], f[lc][j]+f[rc][i-time-j]);
    }
    else
        for (i=time; i<tot; ++i)
            f[root][i]=min((i-time)/5, pic);
}

int main()
{
    cin >> tot;
    dfs(0);
    cout << f[0][tot-1] << endl;
    return 0;
}
