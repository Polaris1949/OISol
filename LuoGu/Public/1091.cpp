#include <iostream>
using namespace std;

int n, maxv;
int h[100], f[100], b[100];

int main()
{
	int i, j;
	cin >> n;

	for (i=0; i<n; i++)
		cin >> h[i];

	f[0]=1;

	for (i=1; i<n; i++)
	{
		maxv=1;

		for (j=i-1; j>=0; j--)
			if (h[j]<h[i]) maxv=max(maxv, f[j]+1);

		f[i]=maxv;
	}

	b[n-1]=1;

	for (i=n-2; i>=0; i--)
	{
		maxv=1;

		for (j=i+1; j<n; j++)
			if (h[i]>h[j]) maxv=max(maxv, b[j]+1);

		b[i]=maxv;
	}

	maxv=1;

	for (i=0; i<n; i++)
		maxv=max(maxv, f[i]+b[i]);

	cout << n-maxv+1 << endl;
	return 0;
}
