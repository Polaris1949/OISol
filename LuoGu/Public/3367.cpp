#include <iostream>
using namespace std;

int n, m, p[10000];

int find_set(int x)
{
	if (x!=p[x]) p[x]=find_set(p[x]);
	return p[x];
}

void union_set(int x, int y)
{
	x=find_set(x); y=find_set(y);
	if (x<y) p[y]=x;
	else p[x]=y;
}

int main()
{
	int i, x, y, z;
	cin >> n >> m;
	
	for (i=0; i<n; i++)
		p[i]=i;
	
	for (i=0; i<m; i++)
	{
		cin >> z >> x >> y;
		--x; --y; --z;
		
		if (z) cout << (find_set(x)==find_set(y)?'Y':'N') << endl;
		else union_set(x, y);
	}
	
	return 0;
}
