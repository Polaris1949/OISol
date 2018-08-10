#include <algorithm>
#include <iostream>
using namespace std;

int n, k, a[50000];
int li[50000], ri[50000];
int ls[50000], rs[50000];

int main()
{
	int i, j, ans=0;
	cin >> n >> k;
	
	for (i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	j=0;
	
	for (i=0; i<n; i++)
	{
		while (j<n && a[i]-a[j]>k) j++;
		li[i]=j;
	}
	
	j=n-1;
	
	for (i=n-1; i>=0; i--)
	{
		while (j>=0 && a[j]-a[i]>k) j--;
		ri[i]=j;
	}
	
	for (i=0; i<n; i++)
	{
		ls[i]=i-li[i]+1;
		if (i>0) ls[i]=max(ls[i], ls[i-1]);
	}
	
	for (i=n-1; i>=0; i--)
	{
		rs[i]=ri[i]-i+1;
		if (i<n-1) rs[i]=max(rs[i], rs[i+1]);
	}
	
	for (i=0; i<n-1; i++)
	{
		ans=max(ans, ls[i]+rs[i+1]);
	}
	
	cout << ans << endl;
	return 0;
}
