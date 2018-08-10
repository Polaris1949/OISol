#include <iostream>
#include <map>
using namespace std;

int n, b, a[100000];
map<int, int> f;

int main()
{
	int i, pos, s, ans=0;
	cin >> n >> b;
	
	for (i=0; i<n; i++)
	{
		cin >> a[i];
		if (a[i]==b) pos=i;
	}
	
	for (i=pos, s=0; i>=0; i--)
	{
		if (a[i]>b) s++;
		if (a[i]<b) s--;
		if (s==0) ans++;
		f[s]++;
	}
	
	for (i=pos+1, s=0; i<n; i++)
	{
		if (a[i]>b) s++;
		if (a[i]<b) s--;
		ans+=f[-s];
	}
	
	cout << ans << endl;
	return 0;
}
