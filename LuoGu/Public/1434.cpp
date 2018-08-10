#include <iostream>
#define ret f[x][y]
using namespace std;

int n, m, ans;
int a[100][100], f[100][100];

int dfs(int x, int y)
{
	if (ret) return ret;
	ret=1;
	if (x>0&&a[x-1][y]>a[x][y]) ret=max(ret, dfs(x-1, y)+1);
	if (x<n-1&&a[x+1][y]>a[x][y]) ret=max(ret, dfs(x+1, y)+1);
	if (y>0&&a[x][y-1]>a[x][y]) ret=max(ret, dfs(x, y-1)+1);
	if (y<m-1&&a[x][y+1]>a[x][y]) ret=max(ret, dfs(x, y+1)+1);
	return ret;
}

int main()
{
	int i, j;
	cin >> n >> m;

	for (i=0; i<n; ++i)
		for (j=0; j<m; ++j)
			cin >> a[i][j];

	for (i=0; i<n; ++i)
		for (j=0; j<m; ++j)
			if (!f[i][j]) ans=max(ans, dfs(i, j));

	cout << ans << endl;
	return 0;
}
