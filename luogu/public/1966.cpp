#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int data, id;
	
	bool operator < (const node& o) const
	{
		return data<o.data;
	}
};

int n;
vector<node> a, b;
vector<int> c, d, num;

int lowbit(int x)
{
	return x&(-x);
}

bool comp(int x, int y)
{
	return c[x]<c[y];
}

int main()
{
	int i, j, s=0;
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	d.resize(n);
	num.resize(n);
	
	for (i=0; i<n; i++)
	{
		a[i].id=i;
		cin >> a[i].data;
	}
	
	sort(a.begin(), a.end());
	
	for (i=0; i<n; i++)
	{
		b[i].id=i;
		cin >> b[i].data;
	}
	
	sort(b.begin(), b.end());
	
	for (i=0; i<n; i++)
	{
		c[b[i].id]=a[i].id;
	}
	
	for (i=0; i<n; i++)
	{
		num[i]=i;
	}
	
	sort(num.begin(), num.end(), comp);
	
	for (i=0; i<n; i++)
		c[num[i]]=i;
	
	for (i=0; i<n; i++)
	{
		for (j=n-c[i]; j>=1; j-=lowbit(j))
		{
			s+=d[j-1];
			s%=99999997;
		}
		
		for (j=n-c[i]; j<=n; j+=lowbit(j))
			d[j-1]++;
	}
	
	cout << s << endl;
	return 0;
}
