#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	
	if (c+d>=e*2) cout << c*a+d*b << endl;
	else if (e*2>=c+d&&a>=b) cout << e*(a+b-(a-b))+c*(a-b) << endl;
	else cout << e*(a+b-(b-a))+d*(b-a) << endl;
	return 0;
}
