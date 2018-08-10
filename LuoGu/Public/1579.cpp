#include <cmath>
#include <cstdio>
using namespace std;

int n, index=0;
int p[2300];

void prime()
{
	int i, j;
	bool f;
	
	for (i=2; i<20000; ++i)
	{
		f=true;
		
		for (j=2; j<=sqrt(i); ++j)
			if (i%j==0)
			{
				f=false; break;
			}
		
		if (f) p[index++]=i;
	}
}

int main()
{
	int i, j, k, pi, pj, pk;
	prime();
	scanf("%d", &n);
	
	for (i=0; i<index; ++i)
	{
		pi=p[i];
		for (j=0; j<index; ++j)
		{
			pj=p[j];
			for (k=0; k<index; ++k)
			{
				pk=p[k];
				if (pi+pj+pk==n)
				{
					printf("%d %d %d\n", pi, pj, pk);
					return 0;
				}
			}
		}
	}
}
