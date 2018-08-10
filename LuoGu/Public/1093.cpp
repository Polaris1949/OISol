#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int s, x, i;
	
	bool operator < (const node& o) const
	{
		if (s!=o.s) return s>o.s;
		else if (x!=o.x) return x>o.x;
		else return i<o.i;
	}
};

int n;
vector<node> v;

int main()
{
	int i, a, b, c;
	cin >> n;
	v.resize(n);
	
	for (i=0; i<n; i++)
	{
		cin >> a >> b >> c;
		
		v[i].s=a+b+c;
		v[i].x=a;
		v[i].i=i;
	}
	
	sort(v.begin(), v.end());
	
	for (i=0; i<5; i++)
		cout << (v[i].i+1) << ' ' << v[i].s << endl; 
	
	return 0;
}
