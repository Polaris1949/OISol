#include <algorithm>
#include <iostream>
using namespace std;

int a[3], g;

int gcd(int x, int y)
{
	if (x%y==0) return y;
	return gcd(y, x%y);
}

int main()
{
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	g=gcd(a[0], a[2]);
	cout << a[0]/g << '/' << a[2]/g << endl;
	return 0;
}
