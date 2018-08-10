#include <iostream>
using namespace std;

long long a, b, c, d, e, f, g;
char o;

int main()
{
	cin >> a >> o >> b >> o >> c >> d >> o >> e >> o >> f >> g;
	cout << ((d-a)*3600+(e-b)*60+(f-c))*g << endl;
	return 0;
}
