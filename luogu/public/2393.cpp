#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	long double n, s=0;
	while (cin >> n) s+=n*1e6;
	cout << fixed << setprecision(5) << s/1e6 << endl;
	return 0;
}
