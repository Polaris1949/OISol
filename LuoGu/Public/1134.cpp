#include <iostream>
using namespace std;

long long n, ans=1;

int main()
{
	cin >> n;

	for (long long i=1; i<=n; ++i)
	{
		ans*=i;
		while (ans%10==0) ans/=10;
		ans%=100000000;
	}

	cout << ans%10 << endl;
	return 0;
}
