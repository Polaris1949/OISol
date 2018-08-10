#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;
vector<vector<int>> g;
vector<int> ideg, odeg, f;

int dfs(int x)
{
	if (f[x]) return f[x];
	if (!odeg[x]) return 1;

	int res=0;

	for (int e : g[x])
		res+=dfs(e);

	return f[x]=res;
}

int main()
{
	int i, x, y;
	cin >> n >> m;
	g.resize(n);
	f.resize(n);
	ideg.resize(n);
	odeg.resize(n);

	for (i=0; i<m; ++i)
	{
		cin >> x >> y;
		g[--x].push_back(--y);
		++ideg[y];
		++odeg[x];
	}

	for (i=0; i<n; ++i)
		if (!ideg[i]&&odeg[i])
			ans+=dfs(i);

	cout << ans << endl;
	return 0;
}
