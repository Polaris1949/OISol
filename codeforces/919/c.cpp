#include <iostream>
using namespace std;

int n, m, k, ans;
bool a[2000][2000];

int main()
{
	int i, j, s, l, r, z=0;
	char ch;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	for (i=0; i<n; ++i)
	{
		s=0;
		l=r=-1;

		for (j=0; j<m; ++j)
		{
			cin >> ch;
			a[i][j]=(ch=='.');

			if (k==1)
			{
				z+=a[i][j];
				continue;
			}

			if (a[i][j])
			{
				if (l==-1)
				{
					l=j;
					r=j;
				}
				else ++r;
			}

			if (!a[i][j] || j+1==m)
			{
				if (l!=-1)
				{
					s=r-l+1;
					if (s>=k) ans+=s-k+1;
					l=r=-1;
				}
			}
		}
	}

	if (k==1)
	{
		cout << z << endl;
		return 0;
	}

	for (j=0; j<m; ++j)
	{
		s=0;
		l=r=-1;

		for (i=0; i<n; ++i)
		{
			if (a[i][j])
			{
				if (l==-1)
				{
					l=i;
					r=i;
				}
				else ++r;
			}

			if (!a[i][j] || i+1==n)
			{
				if (l!=-1)
				{
					s=r-l+1;
					if (s>=k) ans+=s-k+1;
					l=r=-1;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
