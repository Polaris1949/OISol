#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct land
{
	int x, y;

	bool operator < (const land& o) const
	{
		return (x!=o.x?x<o.x:y<o.y);
	}
};

int n;
vector<land> a;
vector<int> x, y;
vector<long long> f;
deque<int> q;

inline double slope(int i, int j)
{
	return ((j>=0?f[j]:0)-(i>=0?f[i]:0))/(y[i+1]-y[j+1]);
}

int main()
{
	int i, j, k;
	cin >> n;
	a.resize(n);
	x.resize(n);
	y.resize(n);
	f.resize(n);
	j=n-1;

	for (i=0; i<n; ++i)
		cin >> a[i].x >> a[i].y;

	sort(a.begin(), a.end());

	for (i=0; i<n; ++i)
	{
		while (j>=0 && a[i].y>=y[j]) --j;
		++j;
		x[j]=a[i].x;
		y[j]=a[i].y;
	}

	q.push_back(-1);

	for (i=0; i<=j; ++i)
	{
		while (q.size()>=2 && slope(q[0], q[1])<x[i]) q.pop_front();

		k=(q.empty()?-1:q[0]);
		f[i]=(k>=0?f[k]:0)+(long long)y[k+1]*x[i];

		while (q.size()>=2 && slope(q[q.size()-2], q.back()) \
		        >slope(q.back(), i)) q.pop_back();

		q.push_back(i);
	}

	cout << f[j] << endl;
	return 0;
}
