#include <iostream>
using namespace std;

int n, m, ans;

int main()
{
	int i, x, s=0;
	cin >> n >> m;

	for (i=0; i<n; ++i)
	{
		cin >> x;
		s+=x;

		if (s>m)
		{
			++ans;
			s=x;
		}
	}

	cout << ans+1 << endl;
	return 0;
}
