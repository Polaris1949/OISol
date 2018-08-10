#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	
	for (i=2; i<=sqrt(n); i++)
	{
		if (n%i==0)
		{
			printf("%d\n", n/i);
			return 0;
		}
	}
}
