#include <iostream>
#include <string>
using namespace std;

int n;
string x, y, z;

int main()
{
	int i;
	cin >> n >> x >> y;

	for (i=0; i<n; ++i)
	{
		if (x[i]<y[i])
		{
			cout << -1 << endl;
			return 0;
		}

		z+=y[i];
	}

	cout << z << endl;
	return 0;
}
