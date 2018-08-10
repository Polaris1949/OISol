#include <algorithm>
#include <iostream>
using namespace std;

int a, b, c, d;
char o;

int main()
{
	cin >> a >> o >> b >> c >> o >> d;
	a*=c;
	b*=d;
	c=__gcd(a, b);
	a/=c;
	b/=c;
	cout << b << ' ' << a << endl;
	return 0;
}
