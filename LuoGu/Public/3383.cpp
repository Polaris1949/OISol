#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool p[10000001];
vector<int> v;

int main()
{
	int i, j, x;
	cin >> n >> m;
	memset(p, true, sizeof(p));
	p[1]=false;
	
	for (i=2; i<=n; i++)
	{
		if (p[i]) v.push_back(i);
		
		for (j=0; j<v.size()&&i*v[j]<=n; j++)
		{
			p[i*v[j]]=false;
			if (i%v[j]==0) break;
		}
	}
	
	for (i=0; i<m; i++)
	{
		cin >> x;
		cout << (p[x] ? "Yes" : "No") << endl;
	}
	
	return 0;
}
