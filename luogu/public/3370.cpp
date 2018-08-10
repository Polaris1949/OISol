#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;
set<string> s;

int main()
{
	int i;
	string x;
	cin >> n;
	
	for (i=0; i<n; ++i)
	{
		cin >> x;
		s.insert(x);
	}
	
	cout << s.size() << endl;
	return 0;
}
