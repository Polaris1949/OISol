#include <cstdio>
using namespace std;

double s, x, last=7.0, n;

int main()
{
	int i;
	scanf("%lf%lf", &s, &x);
	n=7.0;
	if (n==s+x)
	{
		printf("y\n");
		return 0;
	}
	
	while (true)
	{
		if (n>=s-x)
		{
			n+=last*0.98;
			if (n<=s+x) printf("y\n");
			else printf("n\n");
			return 0;
		}
		
		n+=last*0.98;
		last*=0.98;
	}
}
