#include <iostream>
using namespace std;

int n, sum;

int main()
{
	int i, j;
	cin >> n;
	
	for (i=1; i<=n/2; i++)
		for (j=i+1; j<=n/2+1; j++)
		{
			sum=(i+j)*(j-i+1)/2;
			if (sum==n) cout << i << ' ' << j << endl;
			if (sum>n) break;
		}
	
	return 0;
}
