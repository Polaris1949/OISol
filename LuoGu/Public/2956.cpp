#include <iostream>
using namespace std;

int n, m, q;
bool f[240][240];

int main()
{
	int o, i, j, x1, y1, x2, y2, ans=0;
	cin >> n >> m >> q;
	
	for (o=0; o<q; o++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --y1; --x2; --y2;
		
		for (i=x1; i<=x2; i++)
			for (j=y1; j<=y2; j++)
				f[i][j]=true;
	}
	
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			if (f[i][j]) ans++;
	
	cout << ans << endl;
	return 0;
}
