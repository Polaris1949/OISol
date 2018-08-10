#include <cmath>
#include <iostream>
using namespace std;

typedef long long llong;

struct edge
{
	int t, ne;

	edge()
		: t(), ne()
	{
	}
};

int n, cnt;
int h[300000];
edge g[1000000];
llong w[300000];

void add(int a, int b)
{
	cnt++;
	g[cnt].t=b;
	g[cnt].ne=h[a];
	h[a]=cnt;
}

int main()
{
	int i, a, b;
	cin >> n;

	for (i=0; i<n-1; ++i)
	{
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	for (i=1; i<=n; ++i)
		cin >> w[i];

	llong he, rmax, sum=0, maxn=0;
	int node;

	for (i=1; i<=n; ++i)
	{
		node=h[i];
		he=(rmax=w[g[node].t])%10007;
		node=g[node].ne;

		for (; node; node=g[node].ne)
		{
			sum=(sum+he*w[g[node].t])%10007;
			maxn=max(maxn, rmax*w[g[node].t]);
			he=(he+w[g[node].t])%10007;
			rmax=max(rmax, w[g[node].t]);
		}
	}

	cout << maxn << ' ' << (sum*2)%10007 << endl;
	return 0;
}
