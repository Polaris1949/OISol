#include <iostream>
using namespace std;

int m, n, c[10];

int main()
{
	int i, j;
	cin >> m >> n;
	
	for (i=m; i<=n; i++)
	{
		j=i;
		
		while (j>0)
		{
			c[j%10]++;
			j/=10;
		}
	}
	
	for (i=0; i<10; i++)
	{
		if (i) cout << ' ';
		cout << c[i];
	}
	
	cout << endl;
	return 0;
}
