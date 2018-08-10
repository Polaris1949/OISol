#include <iostream>
using namespace std;

int n;
long long ans;

int main()
{
	int i, x, y;
	cin >> n >> ans;
	x=ans;
	
	for (i=1; i<n; i++)
	{
		cin >> y;
		if (y>x) ans+=y-x;
		x=y;
	}
	
	cout << ans << endl;
	return 0;
}
