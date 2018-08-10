#include <iostream>
using namespace std;

int t, n;

int main()
{
	int i, j, x, s;
	bool f;
	cin >> t;
	
	for (i=0; i<t; i++)
	{
		cin >> n;
		s=n;
		
		for (j=1; j<=n; j++)
		{
			x=j; f=false;
			
			while (x)
			{
				if (x%10==7)
				{
					f=true;
					break;
				}
				
				x/=10;
			}
			
			if (f) s--;
		}
		
		cout << s << endl;
	}
	
	return 0;
}
