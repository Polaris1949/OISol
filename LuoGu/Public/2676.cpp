#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, b;
vector<int> v;

int main()
{
	int i, s=0;
	cin >> n >> b;
	v.resize(n);
	
	for (i=0; i<n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end(), greater<int>());
	
	for (i=0; i<n; i++)
	{
		s+=v[i];
		if (s>=b) break;
	}
	
	cout << i+1 << endl;
	return 0;
}
