#include <iostream>
#include <vector>
using namespace std;

int a, n, m, x;
vector<int> f;

int main()
{
	int i, b;
	cin >> a >> n >> m >> x;
	f.push_back(0);
	f.push_back(1);
	
	for (i=2; i<n; ++i)
		f.push_back(f[f.size()-2]+f.back());
	
	b=(m-f[f.size()-3]*a-a)/(f[f.size()-2]-1);
	cout << (f[x-2]+1)*a+(f[x-1]-1)*b << endl;
	return 0;
}
