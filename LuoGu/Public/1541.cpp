#include <iostream>
using namespace std;

int n, m, a[351], card[5], f[41][41][41][41];

int main()
{
	int i, j, k, l, x;
	cin >> n >> m;
	
	for (i=1; i<=n; i++)
		cin >> a[i];
	
	for (i=1; i<=m; i++)
	{
		cin >> x;
		card[x]++;
	}
	
	for (i=0; i<=card[1]; i++)
		for (j=0; j<=card[2]; j++)
			for (k=0; k<=card[3]; k++)
				for (l=0; l<=card[4]; l++)
				{
					if (i) f[i][j][k][l]=max(f[i][j][k][l], f[i-1][j][k][l]);
					if (j) f[i][j][k][l]=max(f[i][j][k][l], f[i][j-1][k][l]);
					if (k) f[i][j][k][l]=max(f[i][j][k][l], f[i][j][k-1][l]);
					if (l) f[i][j][k][l]=max(f[i][j][k][l], f[i][j][k][l-1]);
					
					f[i][j][k][l]+=a[1+i+j*2+k*3+l*4];
				}
	
	cout << f[card[1]][card[2]][card[3]][card[4]] << endl;
	return 0;
}
