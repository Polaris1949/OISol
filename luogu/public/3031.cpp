#include <iostream>
using namespace std;

long long n, t, x, ans;
long long a[100001], b[200001];

int main()
{
	int i;
	cin >> n >> x;
	
	a[0]=n; b[n]=1;
	
	for (i=1; i<=n; i++)
	{
		cin >> t;
		
		if (t>=x) a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	
	t=0;
	
	for (i=1; i<=n; i++)
	{
		if (a[i]>a[i-1]) t-=b[a[i]];
		else t+=b[a[i-1]];
		
		b[a[i]]++; ans+=t;
	}
	
	cout << n*(n+1)/2-ans << endl;
	return 0;
}
