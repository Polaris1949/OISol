#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long llong;

struct node
{
	llong value;
	int index;
	
	node()
	{
	}
	
	node(llong value, int index)
		: value(value), index(index)
	{
	}
	
	bool operator > (const node &b) const
	{
		return value > b.value;
	}
};

int n, k;
llong m;
priority_queue<node, vector<node>, greater<node> > cheap;
priority_queue<node, vector<node>, greater<node> > expensive;
priority_queue<llong, vector<llong>, greater<llong> > recover;
vector<llong> p, c;
vector<bool> used;

int main()
{
	int i, nused=0;
	llong cost;
	node x;
	cin >> n >> k >> m;
	p.resize(n);
	c.resize(n);
	used.resize(n);
	
	for (i=0; i<n; i++)
		cin >> p[i] >> c[i];
	
	for (i=0; i<k; i++)
		recover.push(0);
	
	for (i=0; i<n; i++)
	{
		cheap.push(node(c[i], i));
		expensive.push(node(p[i], i));
	}
	
	while (m>0 && nused<n)
	{
		while (used[cheap.top().index])
			cheap.pop();
		
		while (used[expensive.top().index])
			expensive.pop();
		
		if (recover.top()+cheap.top().value<expensive.top().value)
		{
			x=cheap.top();
			cost=recover.top()+x.value;
			
			if (m<cost) break;
			
			m-=cost;
			recover.pop();
			recover.push(p[x.index]-c[x.index]);
			used[x.index]=true;
		}
		else
		{
			x=expensive.top();
			cost=x.value;
			
			if (m<cost) break;
			
			m-=cost;
			used[x.index]=true;
		}
		
		nused++;
	}
	
	cout << nused << endl;
	return 0;
}
