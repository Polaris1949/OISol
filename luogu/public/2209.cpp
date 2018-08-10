#include <iostream>
#define MAXN 50000
using namespace std;

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
	int i, size = 0;
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
	long long cost = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur < 0)
		{
			printf("-1\n");
			return 0;
		}
		int gasNeeded = min(maxv, (nxt[i] == -1 ? dist :
a[nxt[i]].pos) - a[i].pos);
		if (gasNeeded > cur)
		{
			cost += (long long) (gasNeeded - cur) * (long long) a[i].cost;
			cur = gasNeeded;
		}
		cur -= (i == n-1 ? dist : a[i+1].pos) - a[i].pos;
	}

	if (cur < 0) printf("-1\n");
	else printf("%lld\n", cost);

	return 0;
}
