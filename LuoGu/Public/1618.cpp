#include <cstdio>
using namespace std;

int a, b, c;

bool ok(int x, int y, int z)
{
	if (x%10==0 || y%10==0 || z%10==0) return false;
	bool f[10]={false};
	
	while (x!=0)
	{
		f[x%10]=true;
		x/=10;
	}
	
	while (y!=0)
	{
		f[y%10]=true;
		y/=10;
	}
	
	while (z!=0)
	{
		f[z%10]=true;
		z/=10;
	}
	
	for (int i=1; i<=9; ++i)
		if (!f[i]) return false;
	
	return true;
}

int main()
{
	int i; bool f=false;
	scanf("%d%d%d", &a, &b, &c);
	
	for (i=100; i<=999; ++i)
	{
		if ((double)i/a!=double(i/a)) continue;
		if (!ok(i, i/a*b, i/a*c)) continue;
		if (i/a*c>999) break;
		else
		{
			printf("%d %d %d\n", i, i/a*b, i/a*c);
			f=true;
		}
	}
	
	if (!f) printf("No!!!\n");
	return 0;
}
