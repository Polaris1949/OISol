#include <iostream>
#include <set>
using namespace std;

set<int> a;

int main()
{
	int i, x;
	
	for (i=0; i<10; ++i)
	{
		cin >> x;
		a.insert(x%42);
	}
	
	cout << a.size() << endl;
	return 0;
}
