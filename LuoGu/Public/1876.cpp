#include <cmath>
#include <iostream>
using namespace std;

int n;

int main()
{
	int i;
	cin >> n;
	
	for (i=1; i<=sqrt(n); i++)
	{
		if (i>1) cout << ' ';
		cout << i*i;
	}
	
	cout << endl;
	return 0;
}
