#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

struct node
{
	int p, h;

	bool operator < ( const node &n ) const
	{
		return h<n.h;
	}
} c[50000+5];

int n, d, ans;
set<int> s;
set<int>::iterator it;

int main ( )
{
	int i, j;
	cin >> n >> d;
	j=n;

	for (i=1; i<=n; ++i)
	{
		cin >> c[i].p >> c[i].h;
	}

	sort(c+1, c+1+n) ;

	for (i=n; i; --i)
	{
		for ( ; j && c[j].h>=c[i].h*2; --j)
			s.insert(c[j].p);

		it=s.lower_bound(c[i].p);

		if (it!=s.end() && *it-c[i].p<=d && it--!=s.begin()
		        && c[i].p-*it<=d )
			++ans;
	}

	cout << ans << endl;
	return 0 ;
}
