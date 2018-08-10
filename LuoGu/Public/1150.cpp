#include <iostream>
using namespace std;

int n, k;

int main()
{
	int i, x, y=0, s=0;
	cin >> n >> k;
	
	while (n)
	{
		s+=n;
		x=n;
		n=(x+y)/k;
		y=(x+y)%k;
	}
	
	cout << s << endl;
	return 0;
}
