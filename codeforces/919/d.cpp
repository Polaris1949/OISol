#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, ans;
int d[300000], f[300000][26];
string s;
queue<int> q;
vector<int> g[300000];

int main()
{
	int i, j, x, y, rem;
	cin >> n >> m >> s;
	rem=n;

	for (i=0; i<m; ++i)
	{
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		++d[y];
	}

	for (i=0; i<n; ++i)
		if (!d[i])
		{
			q.push(i);
			f[i][s[i]-'a']=1;
		}

	while (!q.empty())
	{
		x=q.front();
		q.pop();
		--rem;

		for (int e : g[x])
		{
			for (j=0; j<26; ++j)
				f[e][j]=max(f[e][j], f[x][j]+(s[e]-'a'==j));

			--d[e];
			if (!d[e]) q.push(e);
		}
	}

	if (rem)
	{
		cout << "-1" << endl;
		return 0;
	}

	for (i=0; i<n; ++i)
		for (j=0; j<26; ++j)
			ans=max(ans, f[i][j]);

	cout << ans << endl;
	return 0;
}
