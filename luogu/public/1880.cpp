#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const long long INF=0x7fffffffffffffff;
int n;
long long w[400], f[400][400];

int main()
{
	int i, j, l, r;
	long long ans;
	cin >> n;

	for (i=0; i<n; i++)
	{
		cin >> w[i];
		w[i+n]=w[i];
	}

	for (i=0; i<n*2-1; i++)
		w[i]+=w[i-1];

	for (i=1; i<n; i++)
		for (l=0; l+i<n*2-1; l++)
		{
			r=l+i;
			f[l][r]=INF;

			for (j=l; j<r; j++)
				f[l][r]=min(f[l][r], f[l][j]+f[j+1][r]+w[r]-w[l-1]);
		}

	ans=INF;

	for (i=0; i<n; i++)
		ans=min(ans, f[i][i+n-1]);

	cout << ans << endl;

	for (i=1; i<n; i++)
		for (l=0; l+i<n*2-1; l++)
		{
			r=l+i;
			f[l][r]=0;

			for(j=l; j<r; j++)
				f[l][r]=max(f[l][r], f[l][j]+f[j+1][r]+w[r]-w[l-1]);
		}

	ans=0;

	for(i=0; i<n; i++)
		ans=max(ans, f[i][i+n-1]);

	cout << ans << endl;
	return 0;
}
