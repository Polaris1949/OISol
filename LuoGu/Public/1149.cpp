#include <cstdio>
#include <set>
using namespace std;

int c[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, s=0;

int match(int x)
{
	int sum=0;
	
	if (x==0) return c[0];
	
	while (x!=0)
	{
		sum+=c[x%10];
		x/=10;
	}
	
	return sum;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	
	for (i=0; i<1000; ++i)
		for (j=0; j<1000; ++j)
			if (match(i)+2+match(j)+2+match(i+j)==n) ++s;
	
	printf("%d\n", s);
	return 0;
}
