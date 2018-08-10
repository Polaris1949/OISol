#include <iostream>
using namespace std;

int n, m[200], f[200][200];

int main()
{
	int i, j, k, len, t=0;
	cin >> n;

	for (i=0; i<n; i++)
	{
		cin >> m[i];
		m[i+n]=m[i];
	}

	for (len=1; len<n; len++)
		for (i=1; i<n*2-len; i++)
		{
			j=i+len;

			for (k=i; k<j; k++)
			{
				f[i][j]=max(f[i][j], f[i][k]+f[k+1][j]+m[i-1]*m[k]*m[j]);
				if (t<f[i][j]) t=f[i][j];
			}
		}

	cout << t << endl;
	return 0;
}
