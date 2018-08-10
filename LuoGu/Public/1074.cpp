#include <iostream>
using namespace std;

const int w[9][9]=
{
	{6,6,6,6,6,6,6,6,6},
	{6,7,7,7,7,7,7,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,9,10,9,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,7,7,7,7,7,7,6},
	{6,6,6,6,6,6,6,6,6}
}, b[9][9]=
{
	{1,1,1,2,2,2,3,3,3},
	{1,1,1,2,2,2,3,3,3},
	{1,1,1,2,2,2,3,3,3},
	{4,4,4,5,5,5,6,6,6},
	{4,4,4,5,5,5,6,6,6},
	{4,4,4,5,5,5,6,6,6},
	{7,7,7,8,8,8,9,9,9},
	{7,7,7,8,8,8,9,9,9},
	{7,7,7,8,8,8,9,9,9}
};

int p[1<<11], c[1<<11];
int g[10], line[10], col[10], l[10];
int ans, base;

void dfs(int sum)
{
	int x, y, n=10;
	int i, j, k, t, now;

	for (i=0; i<9; i++)
	{
		t=l[i];

		while (t)
		{
			j=t&-t;
			t^=j;
			k=p[j];
			now=c[line[i]&col[k]&g[b[i][k]]];

			if (now<n)
			{
				n=now;
				x=i;
				y=k;
			}
		}
	}

	if (n==10)
	{
		if (sum>ans) ans=sum;
		return;
	}

	l[x]^=1<<y;
	now=line[x]&col[y]&g[b[x][y]];

	while (now)
	{
		t=now&-now;
		now^=t;

		g[b[x][y]]^=t;
		line[x]^=t;
		col[y]^=t;

		dfs(sum+(p[t]+1)*w[x][y]);

		g[b[x][y]]^=t;
		line[x]^=t;
		col[y]^=t;
	}

	l[x]^=1<<y;
}

int main()
{
	int i, j, t;

	for (i=0; i<=9; ++i)
	{
		p[1<<i]=i;
		g[i]=line[i]=col[i]=(1<<9)-1;
	}

	for (i=1; i<=1<<9; ++i)
		c[i]=c[i-(i&-i)]+1;

	for (i=0; i<9; i++)
		for (j=0; j<9; j++)
		{
			cin >> t;

			if (t)
			{
				base+=w[i][j]*t;
				t=1<<t-1;
				g[b[i][j]]^=t;
				line[i]^=t;
				col[j]^=t;
			}
			else l[i]|=1<<j;
		}

	dfs(0);

	if (ans) cout << ans+base << endl;
	else cout << -1 << endl;

	return 0;
}
