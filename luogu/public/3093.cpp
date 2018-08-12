#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct cow
{
	int g, d;

	bool operator < (const cow& c) const
    {
		return g < c.g;
	}
};

cow a[10005];
priority_queue<cow> q;

inline bool by_d(const cow& x, const cow& y)
{
	return x.d > y.d;
}

int main()
{
	int n, i, cur=0, ans=0;
    cin >> n;

	for (i = 0; i < n; i++)
        cin >> a[i].g >> a[i].d;

	sort(a, a + n, by_d);

	for (i = 10000; i >= 1; --i)
    {
		while (cur < n && i <= a[cur].d)
        {
			q.push(a[cur]);
			cur++;
		}

		if (q.size() > 0)
        {
			ans += q.top().g;
			q.pop();
		}
	}

    cout << ans << endl;
	return 0;
}
