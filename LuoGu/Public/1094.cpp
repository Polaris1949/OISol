#include <algorithm>
#include <iostream>
using namespace std;

int w, n;
int p[30000];

int main()
{
	int i, l, r, ans=0;
	cin >> w >> n;
	
	for (i=0; i<n; i++)
		cin >> p[i];
	
	sort(p, p+n);
	l=0; r=n-1;
	
	while (l<=r)
	{
		if (p[l]+p[r]>w) ans++, r--;
		else ans++, r--, l++;
	}
	
	cout << ans << endl;
	return 0;
}
