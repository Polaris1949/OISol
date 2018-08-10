#include <cmath>
#include <cstdio>
using namespace std;

int n, k, a[21], s=0, sum=0;

bool prime(int x)
{
	if (x<2) return false;
	
	for (int i=2; i<=sqrt(x); ++i)
		if (x%i==0) return false;
	
	return true;
}

void dfs(int k, int i)
{
	if (k>::k)
	{
		if (prime(sum)) ++s;
		return;
	}
	
	for (int j=i; j<=n; ++j)
	{
		sum+=a[j];
		dfs(k+1, j+1);
		sum-=a[j];
	}
}

int main()
{
	int i;
	scanf("%d%d", &n, &k);
	
	for (i=1; i<=n; ++i) scanf("%d", &a[i]);
	
	dfs(1, 1);
	printf("%d\n", s);
	return 0;
}
