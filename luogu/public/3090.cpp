#include <iostream>
using namespace std;

int n, k, sum;
int a[1<<22];

int main()
{
	int x, y;
	long long i, u, v;
	cin >> n >> k;

	while (k--)
	{
		cin >> x >> y >> u >> v;

		for (i=1; i<=y; i++)
			a[(u*i+v)%n]+=x;
	}

	for (i=0; i<n; i++)
	{
		sum+=a[i];
		if (sum>0) sum--;
	}

	for (i=0; i<n; i++)
	{
		sum+=a[i];

		if (sum>0) sum--;
		else
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
