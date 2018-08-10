#include <iostream>
using namespace std;

int n, a[40001], b[40001];

int merge(int l, int r)
{
	int c=0, mid=(l+r)/2;
	
	if (l<r)
	{
		c+=merge(l, mid);
		c+=merge(mid+1, r);
		
		int i=l, j=mid+1, k=l;
		
		while (i<=mid || j<=r)
		{
			if (i<=mid && (a[i]<=a[j] || j>r))
			{
				b[k]=a[i];
				i++;
				c+=(j-mid-1);
			}
			else
			{
				b[k]=a[j];
				j++;
			}
			
			k++;
		}
		
		for (i=l; i<=r; i++)
		{
			a[i]=b[i];
		}
	}
	
	return c;
}

int main()
{
	int i;
	cin >> n;
	
	for (i=1; i<=n; i++)
		cin >> a[i];
	
	cout << merge(1, n) << endl;
	return 0;
}
