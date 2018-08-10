#include <iostream>
using namespace std;

int sum(int n)
{
	int i, s=1;

	for (i=2; i*i<n; i++)
		if (n%i==0) s+=i+n/i;

	if (i*i==n) s+=i;
	return s;
}

int main()
{
	int x, y, z;
	cin >> x;

	while (true)
	{
		y=sum(x);
		z=sum(y);
		if (x!=y && x==z) break;
		++x;
	}

	cout << x << ' ' << y << endl;
	return 0;
}
