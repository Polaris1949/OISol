#include <iostream>
using namespace std;

int main()
{
	unsigned int x;
	cin >> x;
	swap(*((unsigned short*)&x), *(((unsigned short*)&x)+1));
	cout << x << endl;
	return 0;
}
