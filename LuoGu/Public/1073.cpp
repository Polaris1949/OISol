#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ans;
vector<bool> v;
vector<int> p, minv, maxv;
vector<vector<int> > gf, gb;
queue<int> q;

int main()
{
	int i, x, y, z;
	cin >> n >> m;
	p.resize(n);
	minv.resize(n, 2147483647);
	maxv.resize(n);
	gf.resize(n);
	gb.resize(n);
	
	for (i=0; i<n; i++)
		cin >> p[i];
	
	for (i=0; i<m; i++)
	{
		cin >> x >> y >> z;
		--x; --y; --z;
		
		if (z)
		{
			gf[x].push_back(y);
			gf[y].push_back(x);
			gb[x].push_back(y);
			gb[y].push_back(x);
		}
		else
		{
			gf[x].push_back(y);
			gb[y].push_back(x);
		}
	}
	
	v=vector<bool>(n);
	q.push(0);
	v[0]=true;
	minv[0]=p[0];
	
	while (!q.empty())
	{
		x=q.front(); q.pop();
		
		for (i=0; i<gf[x].size(); i++)
		{
			y=gf[x][i];
			z=min(p[y], min(minv[x], p[x]));
			
			if (z<minv[y])
			{
				minv[y]=z;
				
				if (!v[y])
				{
					q.push(y);
					v[y]=true;
				}
			}
		}
	}
	
	v=vector<bool>(n);
	q.push(n-1);
	v[n-1]=true;
	maxv[n-1]=p[n-1];
	
	while (!q.empty())
	{
		x=q.front(); q.pop();
		
		for (i=0; i<gb[x].size(); i++)
		{
			y=gb[x][i];
			z=max(p[y], max(maxv[x], p[x]));
			
			if (z>maxv[y])
			{
				maxv[y]=z;
				
				if (!v[y])
				{
					q.push(y);
					v[y]=true;
				}
			}
		}
	}
	
	for (i=0; i<n; i++)
		ans=max(ans, maxv[i]-minv[i]);
	
	cout << ans << endl;
	return 0;
}
