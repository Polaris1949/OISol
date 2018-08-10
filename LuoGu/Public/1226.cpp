#include <iostream>
using namespace std;

long long mpow(long long b, long long p, long long k)
{
	if (!p) return 1;
	
	long long v=mpow(b, p/2, k)%k;
	
	if (p&1) return v*v%k*b%k;
	else return v*v%k;
}

int main()
{
	long long b, p, k;
	cin >> b >> p >> k;
	
	cout << b << '^' << p << " mod " << k << '=' << mpow(b, p, k) << endl;
	return 0;
}
