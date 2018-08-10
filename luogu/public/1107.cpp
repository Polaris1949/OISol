#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;
string a[20];

bool comp(const string& x, const string& y)
{
	return x+y>y+x;
}

int main()
{
	int i;
	cin >> n;

	for (i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n, comp);

	for (i=0; i<n; i++)
		cout << a[i];

	cout << endl;
	return 0;
}
