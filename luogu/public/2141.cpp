#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> a, b;

int main()
{
	int i, x;
	cin >> n;
	
	for (i=0; i<n; ++i)
	{
		cin >> x;
		a.insert(x);
	}
	
	for (auto j=a.begin(); j!=a.end(); ++j)
		for (auto k=a.begin(); k!=a.end(); ++k)
			if (j!=k && a.count(*j+*k)) b.insert(*j+*k);
	
	cout << b.size() << endl;
	return 0;
}
