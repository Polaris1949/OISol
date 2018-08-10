#include <cstdio>
#define arrn 1000001
#define min(x, y) (x<y?x:y)
using namespace std;

int n, m, now=0, ans=arrn;
int r[arrn], p[arrn];
int d[arrn], s[arrn], t[arrn];

bool ok(int mid)
{
	int i, sum=0;
	
	if (now>mid)
		for (i=mid+1; i<=now; ++i)
		{
			p[s[i]]-=d[i];
			p[t[i]+1]+=d[i];
		}
	else
		for (i=now+1; i<=mid; ++i)
		{
			p[s[i]]+=d[i];
			p[t[i]+1]-=d[i];
		}
	
	now=mid;
	
	for (i=1; i<=n; ++i)
	{
		sum+=p[i];
		if (sum>r[i]) return true;
	}
	
	return false;
}

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	
	for (i=1; i<=n; ++i) scanf("%d", &r[i]);
	for (i=1; i<=m; ++i) scanf("%d%d%d", &d[i], &s[i], &t[i]);
	
	int l=1, r=m, mid;
	
	while (l<=r)
	{
		mid=(l+r)/2;
		
		if (ok(mid))
		{
			ans=min(ans, mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	
	if (ans!=arrn) printf("-1\n%d\n", ans);
	else printf("0\n");
	
	return 0;
}
