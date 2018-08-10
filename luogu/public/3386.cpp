#include <cstring>
#include <iostream>
using namespace std;

int n, m, e, ans;
int link[1000];
bool vis[1000];
bool map[1000][1000];

bool dfs(int x)
{
	int i;
	
	for (i=0; i<m; i++)
		if (map[x][i] && !vis[i])
		{
			vis[i]=true;
			
			if (!link[i] || dfs(link[i]))
			{
				link[i]=x;
				return true;
			}
		}
	
	return false;
}

int main()
{
	int i, x, y;
	cin >> n >> m >> e;
	
	for (i=0; i<e; i++)
	{
		cin >> x >> y;
		if (x>m || y>m) continue;
		map[--x][--y]=true;
	}
	
	for (i=0; i<n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) ans++;
	}
	
	cout << ans << endl;
	return 0;
}
