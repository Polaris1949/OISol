#include <iostream>
using namespace std;

long long x, n;

int main()
{
	long long i, ans=1;
	cin >> x >> n;
	
	for (i=0; i<n; i++)
		ans=ans*(x+1);
	
	cout << ans << endl;
	return 0;
}
