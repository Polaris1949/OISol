#include <iostream>
using namespace std;

int n, a, b;

int main()
{
	int i, c=0, s=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> a >> b;
		c+=a+b-8;
		s+=c;
	}
	
	cout << s << endl;
	return 0;
}
