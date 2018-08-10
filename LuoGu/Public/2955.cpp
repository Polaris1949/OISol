#include <iostream>
#include <string>
using namespace std;

int n;

int main()
{
	int i;
	string x;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		cout << ((x.back()-'0')%2?"odd":"even") << endl;
	}
	
	return 0;
}
