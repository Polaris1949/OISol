#include <iostream>
using namespace std;

int n, m, k;

int main()
{
	int i, x, y;
	bool f=false;
	cin >> k >> n >> m;

	for (i=0; i<n; ++i)
	{
		cin >> x >> y;

		if (!x || k/x*y>=m)
		{
			f=true;
			cout << i+1 << ' ';
		}
	}

	if (!f) cout << -1 << endl;
	return 0;
}
