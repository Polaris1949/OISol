#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	cin >> n;

	for (i=0; i<n; ++i)
	{
		cin >> m;
		cout << (m&1?"zs wins":"pb wins") << endl;
	}

	return 0;
}
