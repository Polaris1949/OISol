#include <cmath>
#include <iostream>
using namespace std;

int n, ans=2100000000;

int main()
{
	int i, a, b, x;
	cin >> n;
	
	for (i=0; i<3; i++)
	{
		cin >> a >> b;
		x=ceil(n*1.0/a)*b;
		ans=min(x,ans);
	}
	
	cout << ans << endl;
	return 0;
}
