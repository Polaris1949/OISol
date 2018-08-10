#include <iostream>
#define MOD 10007
#define int long long
using namespace std;

int a, b, k, n, m;
int f[1001][1001];

int c(int n, int m)
{
	if (f[n][m]) return f[n][m];
	if (n==m || m==0) return f[n][m]=1;
	return f[n][m]=(c(n-1, m)+c(n-1, m-1))%MOD;
}

int powmod(int x, int y)
{
	int ret=1;

	while (y)
	{
		if (y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}

	return ret;
}

signed main()
{
	cin >> a >> b >> k >> n >> m;
	cout << powmod(a, n)*powmod(b, m)%MOD*c(k, m)%MOD << endl;
	return 0;
}
