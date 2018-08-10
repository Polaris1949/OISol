#include <iostream>
using namespace std;

int n, m, t, sx, sy, fx, fy, ans=0;
bool a[5][5], v[5][5];

void dfs(int x, int y)
{
	if (x==fx && y==fy)
	{
		ans++;
		return;
	}
	
	v[x][y]=true;
	
	if (x-1>=0)
		if (!a[x-1][y] && !v[x-1][y])
			dfs(x-1, y);
	
	if (x+1<n)
		if (!a[x+1][y] && !v[x+1][y])
			dfs(x+1, y);
	
	if (y-1>=0)
		if (!a[x][y-1] && !v[x][y-1])
			dfs(x, y-1);
	
	if (y+1<m)
		if (!a[x][y+1] && !v[x][y+1])
			dfs(x, y+1);
	
	v[x][y]=false;
}

int main()
{
	int i, x, y;
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	sx--; sy--; fx--; fy--;
	
	for (i=0; i<t; i++)
	{
		cin >> x >> y;
		a[--x][--y]=true;
	}
	
	dfs(sx, sy);
	
	cout << ans << endl;
	return 0;
}
