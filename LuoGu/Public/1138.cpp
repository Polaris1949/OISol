#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;

int main()
{
	int i;
	cin >> n >> k;
	a.resize(n);
	
	for (i=0; i<n; ++i)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	
	if (k<=a.size()) cout << a[k-1] << endl;
	else cout << "NO RESULT" << endl;
	
	return 0;
}
