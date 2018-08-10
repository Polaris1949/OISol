#include <iostream>
using namespace std;

int n, a[100000];
int f[100000][2];

int main()
{
	int i;
	cin >> n;

	for (i=0; i<n; ++i)
		cin >> a[i];

	f[0][0]=f[0][1]=1;

	for (i=1; i<n; ++i)
	{
		if (a[i]>a[i-1]) f[i][0]=f[i-1][1]+1;
		else f[i][0]=f[i-1][0];
		if (a[i]<a[i-1]) f[i][1]=f[i-1][0]+1;
		else f[i][1]=f[i-1][1];
	}

	cout << max(f[n-1][0], f[n-1][1]) << endl;
	return 0;
}
