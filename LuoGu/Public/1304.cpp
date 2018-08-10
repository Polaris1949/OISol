#include <cmath>
#include <iostream>
#include <set>
using namespace std;

int n;
set<int> p;

void prime()
{
	int i, j;
	bool f;

	for (i=2; i<=n-2; i++)
	{
		f=true;

		for (j=2; j<=sqrt(i); j++)
			if (i%j==0)
			{
				f=false;
				break;
			}

		if (f) p.insert(i);
	}
}

int main()
{
	int i, x, y;
	set<int>::iterator j;
	cin >> n;
	prime();

	for (i=4; i<=n; i+=2)
		for (j=p.begin(); j!=p.end(); j++)
		{
			x=*j;
			y=i-x;

			if (p.find(y)!=p.end())
			{
				cout << i << '=' << x << '+' << y << endl;
				break;
			}
		}

	return 0;
}
