#include <iostream>
using namespace std;

int l, n, minv, maxv;

int main()
{
	int i, x;
	cin >> l >> n;

	for (i=0; i<n; ++i)
	{
		cin >> x;
		maxv=max(maxv, max(l-x+1, x));
		minv=max(minv, min(l-x+1, x));
	}

	cout << minv << ' ' << maxv << endl;
	return 0;
}
