#include <iostream>
using namespace std;

int n, map[9][9], d[18][9][9];

int max(int a, int b, int c, int d)
{
	return (((((a>b)?a:b)>c)?((a>b)?a:b):c)>d)? \
		((((a>b)?a:b)>c)?((a>b)?a:b):c):d;
}

int main()
{
	int i, j, k, x, y, v;
	cin >> n;

	while (true)
	{
		cin >> x >> y >> v;
		if (x==0 && y==0 && v==0) break;
		map[x-1][y-1]=v;
	}

	d[0][0][0]=map[0][0];

	for (i=0; i<2*n; i++)
	{
		for (j=0; j<=i && j<n; j++)
		{
			for (k=0; k<=i && k<n; k++)
			{
				if (i==0 && j==0 && k==0) continue;
				d[i][j][k]=map[j][i-j]+map[k][i-k]+max(d[i-1][j][k], \
					d[i-1][j-1][k-1], d[i-1][j-1][k], d[i-1][j][k-1]);
				if (j==k) d[i][j][k]-=map[j][i-j];
			}
		}
	}

	cout << d[2*(n-1)][n-1][n-1] << endl;
	return 0;
}
