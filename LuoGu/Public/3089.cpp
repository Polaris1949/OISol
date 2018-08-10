#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, ans, f[1010][1010];
vector<pair<int, int>> a;

int main()
{
	int i, j, k, o, x;
	cin >> n;
	a.resize(n);

	for (i=0; i<n; ++i)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	for (o=0; o<2; ++o)
	{
		for (i=n-1; i>=0; --i)
		{
			k=n;
			x=0;

			for (j=0; j<=i; ++j)
			{
				while (k-1>i&&a[k-1].first-a[i].first>=a[i].first-a[j].first)
				{
					--k;
					x=max(x, a[k].second+f[k][i]);
				}

				f[i][j]=x;
			}

			ans=max(ans, a[i].second+x);
		}

		for (i=0; i<n; ++i)
			a[i].first=-a[i].first;

		reverse(a.begin(), a.end());
	}

	cout << ans << endl;
	return 0;
}
