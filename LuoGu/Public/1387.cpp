#include <iostream>
using namespace std;

int n, m, s[100][100];
bool a[100][100];

int main()
{
	int i, j, k, ans=0;
	cin >> n >> m;

	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
		{
			cin >> a[i][j];
			s[i][j]=(i>0?s[i-1][j]:0)+(j>0?s[i][j-1]:0)
				-(i>0&&j>0?s[i-1][j-1]:0)+a[i][j];
		}

	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			for (k=ans; k+i<n&&k+j<m; k++)
			{
				if (k*k==s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j])
					ans=max(ans, k);
				else break;
			}

	cout << ans << endl;
	return 0;
}
