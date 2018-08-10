#include <iostream>
using namespace std;

int a, b;

int exgcd(int a, int b, int& x, int& y)
{
	if (!b)
	{
		x=1; y=0; return a;
	}
	else
	{
		int ans=exgcd(b, a%b, x, y);
		int t=x;
		x=y; y=t-(a/b)*y;
		return ans;
	}
}

int equ(int a, int b, int c, int& x, int& y)
{
	int p, q, d;
	d=exgcd(a, b, p, q);
	
	if (c%d) return 0;
	else
	{
		x=c/d*p;
		y=c/d*q;
		return d;
	}
}

int main()
{
	int x, y;
	cin >> a >> b;
	equ(a, b, 1, x, y);
	cout << (x%b+b)%b << endl;
	return 0;
}
