#include <cstring>
#include <iostream>
using namespace std;

int n, sum, a[130], f[130][130], m=0;
bool v[130];

void dfs(int i)
{
	if (m>sum) return;
	if (i==n+1)
	{
		if (sum==m)
		{
			for (int j=1; j<=n; j++)
				cout << a[j] << ' ';

			cout << endl;
			exit(0);
		}

		return;
	}

	for (int j=1; j<=n; j++)
		if (!v[j])
		{
			a[i]=j;
			m+=f[n][i]*j;
			v[j]=true;

			dfs(i+1);

			a[i]=0;
			m-=f[n][i]*j;
			v[j]=false;
		}
}

int main()
{
	int i, j;
	cin >> n >> sum;

	for (i=1; i<=n; i++)
		f[i][1]=1;

	for (i=2; i<=n; i++)
		for (j=2; j<=i; j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1];

	memset(v, false, sizeof(v));
	dfs(1);
}
