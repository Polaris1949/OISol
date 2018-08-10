#include <iostream>
#include <set>
using namespace std;

int n, b[7], c[7];
set<int> a;

int main()
{
	int i, j, x;
	cin >> n;
	
	for (i=0; i<7; ++i)
	{
		cin >> x;
		a.insert(x);
	}
	
	for (i=0; i<n; ++i)
	{
		x=0;
		
		for (j=0; j<7; ++j)
		{
			cin >> b[j];
			x+=!a.count(b[j]);
		}
		
		if (x<7) ++c[x];
	}
	
	for (i=0; i<7; ++i)
		cout << c[i] << ' ';
	
	cout << endl;
	return 0;
}
