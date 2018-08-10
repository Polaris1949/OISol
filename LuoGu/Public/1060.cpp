#include <iostream>
using namespace std;

int n, m, f[30000];

int main()
{
	int i, j, v, p;
	cin >> n >> m;

	for (i=0; i<m; i++)
	{
		cin >> v >> p;

		for (j=n; j>=v; j--)
			f[j]=max(f[j], f[j-v]+v*p);
	}

	cout << f[n] << endl;
	return 0;
}
