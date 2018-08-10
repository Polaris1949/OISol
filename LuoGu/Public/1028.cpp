#include <cstdio>
using namespace std;

int n, f[1001];

int main()
{
	int i, c=0;
	f[0]=1; f[1]=1;
	scanf("%d", &n);
	
	for (i=2; i<=n; i++)
		if (i&1) f[i]=f[i-1];
		else f[i]=f[i-1]+f[i/2];
	
	printf("%d\n", f[n]);
	return 0;
}
