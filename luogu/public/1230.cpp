#include <algorithm>
#include <iostream>
using namespace std;

struct game
{
	int x, y;
	
	bool operator < (const game& o) const
	{
		return y>o.y;
	}
};

int m, n;
game a[500];
bool b[500];

int main()
{
	int i, j;
	cin >> m >> n;

	for (i=0; i<n; ++i)
		cin >> a[i].x;

	for (i=0; i<n; ++i)
		cin >> a[i].y;

	sort(a, a+n);

	for (i=0; i<n; ++i)
		for (j=a[i].x-1; j>=0; --j)
			if (!b[j])
			{
				b[j]=true;
				a[i].y=0;
				break;
			}

	for (i=0; i<n; ++i)
		m-=a[i].y;

	cout << m << endl;
	return 0;
}
