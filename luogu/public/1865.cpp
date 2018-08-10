#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, m, c;
int p[1000000];

void prime()
{
	int i, j;
	bool f;

	for (i=2; i<m; ++i)
	{
		f=true;

		for (j=2; j*j<=i; ++j)
			if (!(i%j))
			{
				f=false;
				break;
			}

		if (f) p[c++]=i;
	}
}

int main()
{
	int i, l, r;
	cin >> n >> m;
	prime();

	for (i=0; i<n; ++i)
	{
		cin >> l >> r;

		if (l<1 || l>m || r<1 || r>m) cout << "Crossing the line" << endl;
		else cout << distance(lower_bound(p, p+c, l), \
			upper_bound(p, p+c, r)) << endl;
	}

	return 0;
}
