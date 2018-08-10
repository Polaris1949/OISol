#include <iostream>
#include <string>
using namespace std;

int m;
string n;

int main()
{
	int i;
	cin >> m >> n;

	for (i=0; i<n.length(); ++i)
		if (n[i]-'0')
		{
			if (i) cout << '+';
			cout << n[i]-'0' << '*' << m << '^' << n.length()-1-i;
		}

	cout << endl;
	return 0;
}
