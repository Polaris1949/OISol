#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> v;

int main()
{
	int i;
	cin >> n;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);

	for (i=3; i<=n; ++i)
		v.push_back(v[v.size()-2]+v.back());

	cout << v[n] << ".00" << endl;
	return 0;
}
