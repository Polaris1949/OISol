#include <algorithm>
#include <iostream>
#define MAXN 50000
using namespace std;

using llong = long long;

struct node
{
	int pos, cost;

	bool operator<(const node& o) const
	{
		return pos < o.pos;
	}
};

node a[MAXN];
int n, maxv, cur, dist;
int s[MAXN], nxt[MAXN];

int main()
{
	int i, siz = 0;
	cin >> n >> maxv >> cur >> dist;

	for (i = 0; i < n; ++i)
		cin >> a[i].pos >> a[i].cost;

	sort(a, a + n);

	for (i = n-1; i >= 0; --i)
	{
		while (siz > 0 && a[s[siz-1]].cost >= a[i].cost) --siz;
		nxt[i] = (siz == 0 ? -1 : s[siz-1]);
		s[siz++] = i;
	}

	cur -= a[0].pos;
	llong cost = 0;

	for (i = 0; i < n; ++i)
	{
		if (cur < 0)
		{
			cout << "-1" << endl;
			return 0;
		}

		int v = min(maxv, (nxt[i] == -1 ? dist : a[nxt[i]].pos) - a[i].pos);

		if (v > cur)
		{
			cost += llong(v - cur) * llong(a[i].cost);
			cur = v;
		}

		cur -= (i == n-1 ? dist : a[i+1].pos) - a[i].pos;
	}

	if (cur < 0) cout << "-1" << endl;
	else cout << cost << endl;

	return 0;
}
