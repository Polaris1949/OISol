#include <algorithm>
#include <cstdio>
using namespace std;

int n, s, a, b, sum=0;
int x[5000], y[5000];

int main()
{
	int i, j;
	scanf("%d%d%d%d", &n, &s, &a, &b);
	
	for (i=0; i<n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		if (x[i]>a+b) y[i]=s+1;
	}
	
	sort(y, y+n);
	
	for (i=0; i<n; ++i)
	{
		if ((s-=y[i])>=0) ++sum;
		else break;
	}
	
	printf("%d\n", sum);
	return 0;
}
