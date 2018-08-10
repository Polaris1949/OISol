#include <cmath>
#include <iostream>
using namespace std;

int n;

int main()
{
	int i, e, l=0, s=0;
	double x, b=10;
	cin >> n;

	for (i=0; i<n; i++)
	{
		cin >> x >> e;
		b-=x;
		if (b<=0) break;
		if (b>10) b=10;
		s+=e;
	}

	while (true)
	{
		e=pow(2, l);

		if (s>=e)
		{
			s-=e;
			l++;
		}
		else break;
	}

	cout << l << ' ' << s << endl;
	return 0;
}
