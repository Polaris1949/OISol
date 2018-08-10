#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct node
{
	int s, id;
	
	bool operator < (const node& o) const
	{
		return s<o.s;
	}
};

node a[100000];
int n, p[100000];
bool ok[100000];

int main()
{
	int i, x, ans=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		a[i].s=(i>0?a[i-1].s:0)+x;
		a[i].id=i;
	}
	
	sort(a, a+n);
	
	if (a[0].s<=0)
	{
		cout << "-1" << endl;
		return 0;
	}
	
	for (i=0; i<n-1; i++)
		if (a[i].s==a[i+1].s)
		{
			cout << "-1" << endl;
			return 0;
		}
	
	for (i=0; i<n; i++)
		p[a[i].id]=i;
	
	memset(ok, false, sizeof(ok));
	
	for (i=0; i<n; i++)
		if (!ok[i])
		{
			ok[i]=true;
			
			for (x=p[i]; x!=i; x=p[x])
			{
				ans++;
				ok[x]=true;
			}
		}
	
	cout << ans << endl;
	return 0;
}
