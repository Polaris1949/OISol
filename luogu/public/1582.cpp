#include <iostream>
#define int long long
using namespace std;

int n, k, ans;

int cbit(int x)
{
	int s=0;

	while (x)
	{
		if (x&1) ++s;
		x>>=1;
	}

	return s;
}

signed main()
{
	cin >> n >> k;

	while (cbit(n)>k)
	{
		ans+=n&-n;
		n+=n&-n;
	}

	cout << ans << endl;
	return 0;
}
