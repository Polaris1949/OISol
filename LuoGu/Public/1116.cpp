#include <iostream>
using namespace std;

int n, ans, a[10000], b[10000];

void mergesort(int l, int r)
{
	if (r-l==1) return;

	mergesort(l, (l+r)/2);
	mergesort((l+r)/2, r);

	int i=l, j=(l+r)/2, k=l;

	while (i<(l+r)/2 && j<r)
	{
		if (a[i]<=a[j])
			b[k++]=a[i++];
		else
		{
			b[k++]=a[j++];
			ans+=((l+r)/2-i);
		}
	}

	if (i<(l+r)/2 && j>=r)
		while (i<(l+r)/2) b[k++]=a[i++];

	if (i>=(l+r)/2 && j<r)
		while (j<r)
		{
			ans+=((l+r)/2-i);
			b[k++]=a[j++];
		}

	for (i=l; i<r; i++)
		a[i]=b[i];
}

int main()
{
	int i;
	cin >> n;

	for (i=0; i<n; i++)
		cin >> a[i];

	mergesort(0, n);

	cout << ans << endl;
	return 0;
}
