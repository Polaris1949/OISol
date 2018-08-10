#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1005;

int n;
int cows [MAXN];
int best [MAXN][2], best2 [MAXN][2];

inline void smin (int &a, int b)
{
	if (b < a) a = b;
}

int main ()
{
	memset (best, 63, sizeof (best));

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> cows[i];

	cows [++n] = 0;
	sort (cows + 1, cows + n + 1);

	for (int i = 1; i <= n; i++)
		if (cows [i] == 0)
			best [i][0] = 0;

	for (int len = 1; len < n; len++)
	{
		int ccount = n - len;

		memset(best2, 63, sizeof (best2));

		for (int i = 1; i + len <= n + 1; i++)
		{
			smin(best2[i-1][0], best[i][0]+ccount*(cows[i]-cows [i - 1]));
			smin(best2[i-1][0], best[i][1]+ccount*(cows[i+len-1]-cows[i-1]));

			smin(best2[i][1], best[i][0]+ccount*(cows[i+len]-cows[i]));
			smin(best2[i][1], best[i][1]+ccount*(cows[i+len]-cows[i+len-1]));
		}

		memcpy (best, best2, sizeof (best));
	}

	cout << (best[1][0]<best[1][1]?best[1][0]:best[1][1]) << endl;
	return 0;
}
