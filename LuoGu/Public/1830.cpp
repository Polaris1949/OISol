#include <iostream>
using namespace std;

int n, m, p, q;
int x1[100], y1[100], x2[100], y2[100];

int main()
{
	int i, j, vx, vy, ans, pos;
	cin >> n >> m >> p >> q;

	for (i=0; i<p; ++i)
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

	for (i=0; i<q; ++i)
	{
		cin >> vx >> vy;
		ans=0;

		for (j=0; j<p; ++j)
			if (vx>=x1[j]&&vx<=x2[j]&&vy>=y1[j]&&vy<=y2[j])
			{
				++ans;
				pos=j;
			}

		if (ans) cout << "Y " << ans << ' ' << pos+1 << '\n';
		else cout << "N\n";
	}

	return 0;
}
