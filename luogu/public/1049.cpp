#include <iostream>
using namespace std;

int v, n, f[20001];

int main()
{
	int i, j, x;
	cin >> v >> n;

	for (i=0; i<n; i++)
	{
		cin >> x;

		for (j=v; j>=1; j--)
			if (j>=x) f[j]=max(f[j], f[j-x]+x);
	}

	cout << v-f[v] << endl;
	return 0;
}
