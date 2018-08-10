#include <iostream>
using namespace std;

int n, m, f[1001];

int main()
{
	int i, j, t, w;
	cin >> n >> m;

	for (i=0; i<m; i++)
	{
		cin >> t >> w;

		for (j=n; j>=t; j--)
			f[j]=max(f[j], f[j-t]+w);
	}

	cout << f[n] << endl;
	return 0;
}
