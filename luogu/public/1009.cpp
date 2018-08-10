#include<iostream>
#include<cstdio>
using namespace std;

int n, a[5000], f[5000];

void add(int v, int t)
{
	f[t]=f[t]+v;
	f[t+1]=f[t+1]+f[t]/10000;
	f[t]=f[t]%10000;
}

int main()
{
	int i, j, k;
	cin >> n;
	a[1]=1; k=1;
	
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=k; ++j)
			a[j]=a[j]*i;
		
		for (j=1; j<=k; ++j)
		{
			a[j+1]=a[j+1]+a[j]/10000;
			a[j]=a[j]%10000;
		}
		
		if (a[k+1]>0) ++k;
		
		for (j=1; j<=k; ++j)
			add(a[j], j);
	}
	
	cout << f[k];
	
	for (j=k-1; j>=1; --j)
		printf("%04d", f[j]);
	
	cout << endl;
	return 0;
}
