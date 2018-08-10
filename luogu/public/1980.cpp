#include <iostream>
using namespace std;

int n, x, ans;

int main()
{
	int i, j;
	cin >> n >> x;
	
	for (i=1; i<=n; ++i)
	{
		j=i;
		
		while (j)
		{
			if (j%10==x) ++ans;
			j/=10;
		}
	}
	
	cout << ans << endl;
	return 0;
}
