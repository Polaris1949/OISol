#include <iostream>
using namespace std;

int n, m, k, x;

int qpow(int a, int b)
{
	int r=1;
	
	while (b)
	{
		if (b&1) r=r*a%n;
		a=a*a%n;
		b>>=1;
	}
	
	return r;
}

int main()
{
	cin >> n >> m >> k >> x;
	cout<< (x%n+m%n*qpow(10, k)%n)%n << endl;
	return 0;
}
