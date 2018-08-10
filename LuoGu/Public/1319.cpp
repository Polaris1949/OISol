#include <iostream>
using namespace std;

int main()
{
	int n, i, x, m=0;
	bool f=false;
	cin >> n;

	while (cin >> x)
	{
		for (i=0; i<x; ++i)
		{
			cout << f;
			++m;

			if (m>=n)
			{
				cout << endl;
				m=0;
			}
		}

		f=!f;
	}

	return 0;
}
