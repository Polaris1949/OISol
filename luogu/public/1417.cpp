#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long llong;

struct node
{
	int a, b, c;
};

node a[100001];
llong f[100001], ans;
int t, n;

bool comp(const node& a, const node& b)
{
	return (llong)a.c*(llong)b.b<(llong)b.c*(llong)a.b;
}

int main()
{
	int i, j;
	cin >> t >> n;

	for (i = 0; i < n; i++)
		cin >> a[i].a;

	for (i = 0; i < n; i++)
		cin >> a[i].b;

	for (i = 0; i < n; i++)
		cin >> a[i].c;

	sort(a, a+n, comp);

	memset(f, 0xff, sizeof(f));
	f[0]=0;

	for (i=0; i<n; i++)
	{
		for (j=t; j>=0; j--)
			if (f[j]!=-1 && j+a[i].c<=t)
				f[j+a[i].c]=max(f[j+a[i].c], f[j]+(llong)a[i].a
					-(llong)(j+a[i].c)*(llong)a[i].b);
	}

	for (i=0; i<=t; i++)
		ans = max(ans, f[i]);

	cout << ans << endl;
	return 0;
}
