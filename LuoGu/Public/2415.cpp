#include <iostream>
using namespace std;

int main()
{
	int c=0;
	long long x, s=0;

	while (cin >> x)
	{
		s+=x;
		c++;
	}

	s<<=c-1;
	cout << s << endl;
	return 0;
}
