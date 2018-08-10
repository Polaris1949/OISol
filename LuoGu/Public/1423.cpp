#include <iostream>
using namespace std;

double n;

int main()
{
	int i=0;
	double x=2, s=0;
	cin >> n;
	
	while (true)
	{
		s+=x; i++;
		if (s>=n) break;
		x*=0.98;
	}
	
	cout << i << endl;
	return 0;
}
