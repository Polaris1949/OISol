#include <iostream>
using namespace std;

int n, a[39][39];

int main()
{
	cin >> n;
	int i=0, j=n/2, k=1;
	a[i][j]=k++;
	
	while (k<=n*n)
	{
		if (i==0 && j!=n-1)
		{
			i=n-1; j++;
		}
		else if (j==n-1 && i!=0)
		{
			i--; j=0;
		}
		else if (i==0 && j==n-1)
		{
			i++;
		}
		else if (a[i-1][j+1]==0)
		{
			i--; j++;
		}
		else
		{
			i++;
		}
		
		a[i][j]=k++;
	}
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			cout << a[i][j] << ' ';
		
		cout << endl;
	}
	
	return 0;
}
