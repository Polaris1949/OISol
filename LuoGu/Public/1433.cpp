#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int n;
bool v[16];
double x[16], y[16], d[16][16], ans=268435456;

void search(int q, double w, int r)
{
	if (w>ans) return;

	if (q==n)
	{
		if (w<ans) ans=w;
		return;
	}
	else
		for (int i=1; i<=n; i++)
			if (!v[i])
			{
				v[i]=true;
				search(q+1, w+d[r][i], i);
				v[i]=false;
			}
}

int main()
{
	int i, j;
	cin >> n;

	for (i=1; i<=n; i++)
		cin >> x[i] >> y[i];

	for (i=0; i<=n; i++)
		for (j=0; j<=n; j++)
			d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));

	search(0, 0, 0);
	cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
	return 0;
}
