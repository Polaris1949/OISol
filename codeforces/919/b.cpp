#include <cstdlib>
#include <iostream>
using namespace std;

int k, res;

bool ok(int x)
{
	int s=0;
	while (x)
	{
		s+=x%10;
		x/=10;
		if (s>10) return false;
	}
	return s==10;
}

int main()
{
	int i=1;
	cin >> k;
	
	while (1)
	{
		if (ok(i)) ++res;
		if (res==k)
		{
			cout << i << endl;
			return 0;
		}
		++i;
	}
}
