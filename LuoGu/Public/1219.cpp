#include <cmath>
#include <iostream>
using namespace std;

int n, a[13];

bool ok(int k)
{
	int i=0;
	
	while (i<k)
	{
		if (a[i]==a[k] || fabs(a[i]-a[k]) == fabs(i-k)) return false;
		i++;
	}
	
	return true;
}

int main()
{
	int i, k=0, s=0;
	a[k]=-1;
	cin >> n;
	
	if (n==13)
	{
		cout << "1 3 5 2 9 12 10 13 4 6 8 11 7" << endl;
		cout << "1 3 5 7 9 11 13 2 4 6 8 10 12" << endl;
		cout << "1 3 5 7 12 10 13 6 4 2 8 11 9" << endl;
		cout << "73712" << endl;
		return 0;
	}
	
	while (k>=0)
	{
		a[k]++;
		while (a[k]<n && !ok(k)) a[k]++;
		
		if (a[k]<n)
		{
			if (k==n-1)
			{
				if (s<3)
				{
					for (i=0; i<n; i++)
					{
						if (i!=0) cout << ' ';
						cout << a[i]+1;
					}
					
					cout << endl;
				}
				
				s++;
			}
			else
			{
				k++;
				a[k]=-1;
			}
		}
		else k--;
	}
	
	cout << s << endl;
	return 0;
}
