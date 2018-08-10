#include <algorithm>
#include <iostream>
using namespace std;

int x, y;

int main()
{
	int i, j, ans=0;
	cin >> x >> y;
	
	for (i=x; i<=y; i+=x)
		for (j=x; j<=y; j+=x)
			if (__gcd(i, j)==x && x*y==i*j) ans++;
	
	cout << ans << endl;
	return 0;
}
