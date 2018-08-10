#include <cstring>
#include <iostream>
using namespace std;

int n, m, f[3000][3000];
bool p;

void dfs(int x, int y)
{
	if (p) return;
	
	if (x>=n || y>=m)
	{
		if (f[x%n][y%m]==2 || f[x%n+n][y%m]==2
			|| f[x%n][y%m+m]==2 || f[x%n+n][y%m+m]==2)
		{
			p=true;
			f[x%n][y%m]=3;
			return;
		}
	}
	
	f[x][y]=2;
	
	if (f[(x+1+2*n)%(2*n)][y]==0) dfs((x+1+2*n)%(2*n), y);
	if (f[(x-1+2*n)%(2*n)][y]==0) dfs((x-1+2*n)%(2*n), y);
	if (f[x][(y-1+2*m)%(2*m)]==0) dfs(x, (y-1+2*m)%(2*m));
	if (f[x][(y+1+2*m)%(2*m)]==0) dfs(x, (y+1+2*m)%(2*m));
}

int main()
{
	int i, j, x, y;
	char c;
	
	while (cin >> n >> m)
	{
		memset(f, 0, sizeof(f));
		p=false;
		
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
			{
				cin >> c;
				
				if (c=='#') f[i][j]=1;
				
				if (c=='S')
				{
					x=i; y=j;
				}
			}
		
		for (i=0; i<n; i++)
			for (j=m; j<2*m; j++)
				f[i][j]=f[i][j-m];
		
		for (i=n; i<2*n; i++)
			for (j=0; j<2*m; j++)
				f[i][j]=f[i-n][j];
		
		dfs(x, y);
		cout << (p ? "Yes" : "No") << endl;
	}
	
	return 0;
}
