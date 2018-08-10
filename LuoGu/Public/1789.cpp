#include <iostream>
using namespace std;

int n, m, k;
bool f[100][100];

int main()
{
	int o, i, j, x, y, ans=0;
	cin >> n >> m >> k;
	
	for (o=0; o<m; o++)
	{
		cin >> x >> y;
		--x; --y;
		
		for (i=(x-2>=0?x-2:0); i<=(x+2<n?x+2:n-1); i++)
			for (j=(y-2+abs(x-i)>=0?y-2+abs(x-i):0);
				j<=(y+2-abs(x-i)<n?y+2-abs(x-i):n-1); j++)
				f[i][j]=true;
	}
	
	for (o=0; o<k; o++)
	{
		cin >> x >> y;
		--x; --y;
		
		for (i=(x-2>=0?x-2:0); i<=(x+2<n?x+2:n-1); i++)
			for (j=(y-2>=0?y-2:0); j<=(y+2<n?y+2:n-1); j++)
				f[i][j]=true;
	}
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			if (!f[i][j]) ans++;
	
	cout << ans << endl;
	return 0;
}
