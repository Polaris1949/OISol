#include <iostream>
using namespace std;

int n, m;
int s[500001], c[500001];

int main()
{
	int i, j, op, x, y, k, ans;
	cin >> n >> m;
	
	for (i=1; i<=n; i++)
	{
		cin >> s[i];
		
		for (j=i; j<=n; j+=j&-j)
			c[j]+=s[i]-s[i-1];
	}
	
	for (i=1; i<=m; i++)
	{
		cin >> op;
		
		if (op==1)
		{
			cin >> x >> y >> k;
			s[x]+=k; s[y+1]-=k;
			
			for (j=x; j<=n; j+=j&-j)
				c[j]+=k;
			
			for (j=y+1; j<=n; j+=j&-j)
				c[j]-=k;
		}
		else
		{
			cin >> x; ans=0;
			
			for (j=x; j>=1; j-=j&-j)
				ans+=c[j];
			
			cout << ans << endl;
		}
	}
	
	return 0;
}
