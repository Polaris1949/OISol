#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> d(ll st, const vector<vector<ll> >& e)
{
	vector<ll> d(e.size(), -1);
	queue<ll> q;
	ll i, x, y;
	
	d[st]=0;
	q.push(st);
	
	while (!q.empty())
	{
		x=q.front(); q.pop();
		
		for (i=0; i<e[x].size(); ++i)
		{
			y=e[x][i];
			
			if (d[y]==-1)
			{
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
}

int main()
{
	freopen("1.in", "r", stdin);
	ll b, e, p, n, m;
	ll i, x, y;
	ll ans=ll(1000)*1000*1000*1000;
	scanf("%lld%lld%lld%lld%lld", &b, &e, &p, &n, &m);
	vector<vector<ll> > ge(n, vector<ll>());
	
	for (i=0; i<m; ++i)
	{
		scanf("%lld%lld", &x, &y);
		--x; --y;
		
		ge[x].push_back(y);
		ge[y].push_back(x);
	}
	
	vector<ll> d0=d(0, ge);
	vector<ll> d1=d(1, ge);
	vector<ll> dn=d(n-1, ge);
	
	for (i=0; i<m; ++i)
		ans=min(ans, d0[i]*b+d1[i]*e+dn[i]*p);
	
	printf("%lld\n", ans);
	return 0;
}
