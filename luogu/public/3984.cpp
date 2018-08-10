#include <iostream>
using namespace std;

int n, t, ans;

int main()
{
	int i, x, y;
	cin >> n >> t >> x;
	
	for (i=1; i<n; ++i)
	{
		cin >> y;
		ans+=min(y-x, t);
		x=y;
	}
	
	cout << ans+t << endl;
	return 0;
}
