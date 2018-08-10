#include <iostream>
using namespace std;

int n, x, f[200000];

int main()
{
	int i, ans=-2147483648;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		if (i) f[i]=max(f[i-1]+x, x);
		else f[i]=x;
		if (f[i]>ans) ans=f[i];
	}
	
	cout << ans << endl;
	return 0;
}
