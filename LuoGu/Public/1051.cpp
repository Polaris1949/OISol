#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node
{
	int data, id;
	string name;
	
	bool operator < (const node& o) const
	{
		if (data!=o.data) return data>o.data;
		else return id<o.id;
	}
};

int n;
vector<node> v;

int main()
{
	int i, a, b, e, x, s=0;
	char c, d;
	cin >> n;
	v.resize(n);
	
	for (i=0; i<n; i++)
	{
		cin >> v[i].name >> a >> b >> c >> d >> e;
		v[i].id=i; x=0;
		
		if (a>80 && e>=1) x+=8000;
		if (a>85 && b>80) x+=4000;
		if (a>90) x+=2000;
		if (a>85 && d=='Y') x+=1000;
		if (b>80 && c=='Y') x+=850;
		
		v[i].data=x;
		s+=x;
	}
	
	sort(v.begin(), v.end());
	cout << v[0].name << endl;
	cout << v[0].data << endl;
	cout << s << endl;
	return 0;
}
