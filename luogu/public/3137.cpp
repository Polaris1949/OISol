#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long sumn2(long long v)
{
	return v*(v+1)*(2*v+1)/6;
}

int main()
{
	int n, i, c=0;
	long long ans=0;
	cin >> n;
	
	vector<long long> a(n);
	
	for (i=0; i<n; i++)
	{
		cin >> a[i];
		c=max(0ll, c+a[i]-1);
	}
	
	for (i=0; ; i++)
	{
		if (c==0)
		{
			rotate(a.begin(), a.begin()+i, a.begin()+n);
			break;
		}
		
		c=max(0ll, c+a[i]-1);
	}
	
	for (i=0; i < n; i++)
	{
		ans+=sumn2(a[i]+c-1)-sumn2(c-1);
		c=max(0ll, c+a[i]-1);
	}
	
	cout << ans << endl;
	return 0;
}
