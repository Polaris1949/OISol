#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, x, y, ans;
vector<int> a, b;

int main()
{
	int i;
	cin >> n >> x >> y;
	a.resize(n);
	b.resize(n);

	for (i=0; i<n; i++)
		cin >> a[i] >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (i=0; i<n; i++)
	{
		if (a[i]<b[i]) ans+=(b[i]-a[i])*x;
		else ans+=(a[i]-b[i])*y;
	}

	cout << ans << endl;
	return 0;
}
