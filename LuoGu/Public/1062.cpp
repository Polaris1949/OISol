#include <iostream>
#define int long long
using namespace std;

int k, n, ans;
int p[1000];

int powk(int x)
{
	if (p[x]) return p[x];
	if (x&1) return p[x]=powk(x>>1)*powk(x>>1)*k;
	else return p[x]=powk(x>>1)*powk(x>>1);
}

signed main()
{
	bool b;
	int i=0;
	cin >> k >> n;
	p[0]=1;
	
	while (n)
	{
		b=n&1;
		if (b) ans+=powk(i);
		++i;
		n>>=1;
	}
	
	cout << ans << endl;
	return 0;
}
