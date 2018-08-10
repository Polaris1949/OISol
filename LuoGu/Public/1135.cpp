#include <iostream>
using namespace std;

int n, a, b, k[200], ans=2000000000;
bool v[200];

void dfs(int i, int j)
{
	if (j>ans) return;
	if (i==b)
	{
		ans=j;
		return;
	}
	
	if (i+k[i]<n && !v[i+k[i]])
	{
		v[i+k[i]]=true;
		dfs(i+k[i], j+1);
		v[i+k[i]]=false;
	}
	if (i-k[i]>=0 && !v[i-k[i]])
	{
		v[i-k[i]]=true;
		dfs(i-k[i], j+1);
		v[i-k[i]]=false;
	}
}

int main()
{
	int i;
	cin >> n >> a >> b;
	a--; b--;
	
	for (i=0; i<n; i++)
		cin >> k[i];
	
	dfs(a, 0);
	
	if (ans==2000000000) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
