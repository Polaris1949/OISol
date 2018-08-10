#include <iostream>
using namespace std;

int n, ans=0;
int a[248], f[248][248];

int main()
{
	int i, j, k, len;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	for (len=1; len<=n; len++)
	{
		for (i=0; i+len<=n; i++)
		{
			j=i+len-1;
			f[i][j]=-1;
			
			if (len==1) f[i][j]=a[i];
			
			for (k=i; k<j; k++)
			{
				if (f[i][k]==f[k+1][j] && f[i][k]>0)
				{
					f[i][j]=max(f[i][j], f[i][k]+1);
				}
			}
			
			ans=max(ans, f[i][j]);
		}
	}
	
	cout << ans << endl;
	return 0;
}
