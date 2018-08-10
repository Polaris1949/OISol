#include <iostream>
using namespace std;

int x, n;

int main()
{
	int i, s=0;
	cin >> x >> n;
	
	for (i=0; i<n; i++)
	{
		if (x>=1 && x<=5) s+=250;
		if (x==7) x=1; else x++;
	}
	
	cout << s << endl;
	return 0;
}
