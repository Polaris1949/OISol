#include <iomanip>
#include <iostream>
using namespace std;

typedef long double ld;

int n, m;
ld minv=1000000000;

int main()
{
	int i, a, b;
	cin >> n >> m;

	for (i=0; i<n; ++i)
	{
		cin >> a >> b;
		minv=min(minv, ld(a)/ld(b));
	}

	cout << fixed << setprecision(8) << minv*m << endl;
	return 0;
}
