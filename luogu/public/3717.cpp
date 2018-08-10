#include <cmath>
#include <iostream>
using namespace std;

int n, m, r;
bool f[100][100];

int main()
{
	int o, i, j, x, y, ans=0;
	double d;
	cin >> n >> m >> r;
	
	for (o=0; o<m; o++)
	{
		cin >> x >> y;
		--x; --y;
		
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
			{
				d=sqrt((x-i)*(x-i)+(y-j)*(y-j));
				if (d<=r) f[i][j]=true;
			}
	}
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			if (f[i][j]) ans++;
	
	cout << ans << endl;
	return 0;
}
