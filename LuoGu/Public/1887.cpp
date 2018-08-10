#include <iostream>
using namespace std;

int main()
{
	int x, y, d, m, i;
	cin >> x >> y;
	m=x%y;
	d=x/y;

	for (i=m; i<y; ++i) cout << d << ' ';
	for (i=0; i<m; ++i) cout << d+1 << ' ';

	cout << endl;
	return 0;
}
