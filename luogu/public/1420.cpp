#include <iostream>
using namespace std;

int n;

int main()
{
	int i, x, y, sum=1, ans=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		
		if (i)
		{
			if (x==y+1) sum++;
			else sum=1;
			
			if (sum>ans) ans=sum;
		}
		
		y=x;
	}
	
	cout << ans << endl;
	return 0;
}
