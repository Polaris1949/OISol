#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct point
{
	int x, y;
	
	bool operator < (const point& o) const
	{
		return x<o.x;
	}
};

int n;
vector<point> v;
vector<point> a, b;

int main()
{
	int i, j, x, y, ai, bi, xb, ans;
	cin >> n;
	v.resize(n);
	
	for (i=0; i<n; i++)
	{
		cin >> v[i].x >> v[i].y;
	}
	
	sort(v.begin(), v.end());
	ans=n;
	
	for (i=0; i<n; i++)
	{
		a.clear();
		b.clear();
		
		for (j=0; j<n; j++)
		{
			if (v[j].y>v[i].y)
			{
				a.push_back(v[j]);
			}
			else
			{
				b.push_back(v[j]);
			}
		}
		
		ai=0; bi=0;
		
		while (ai<a.size() || bi<b.size())
		{
			xb=INT_MAX;
			
			if (ai<a.size())
			{
				xb=min(xb, a[ai].x);
			}
			
			if (bi<b.size())
			{
				xb=min(xb, b[bi].x);
			}
			
			while (ai<a.size() && a[ai].x == xb)
				ai++;
			
			while (bi<b.size() && b[bi].x == xb)
				bi++;
			
			ans=min(ans, max(max(ai, (int)a.size()-ai),
				max(bi, (int)b.size()-bi)));
		}
	}
	
	cout << ans << endl;
	return 0;
}
