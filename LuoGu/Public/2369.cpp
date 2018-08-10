#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<short> v;

int main()
{
	int i;
	cin >> n >> m;
	v.resize(n);

	for (i=0; i<n; ++i)
		cin >> v[i];

	partial_sort(v.begin(), v.begin()+m, v.end());

	for (i=0; i<m; ++i)
		cout << v[i] << endl;

	return 0;
}
