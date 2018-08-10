#include <iostream>
#include <vector>
#include <polaris/segment_tree>
using namespace std;
using namespace polaris;

typedef long long llong;

struct delta
{
	llong plus, mul;
	
	delta()
		: plus(0), mul(1)
	{
	}
	
	bool operator == (const delta& x) const
	{
		return plus==x.plus&&mul==x.mul;
	}
};

int n, m, p;

struct data_func_t
{
	llong operator() (llong x, llong y) const
	{
		return (x+y)%p;
	}
};

struct search_func_t
{
	void operator() (segment_tree_node<llong, delta>* root, delta x) const
	{
		root->mark().mul=(root->mark().mul*x.mul)%p;
		root->mark().plus=(root->mark().plus*x.mul)%p;
		root->data()=(root->data()*x.mul)%p;
		root->mark().plus=(root->mark().plus+x.plus)%p;
		root->data()=(root->data()+root->segment()*x.plus)%p;
	}
};

struct mod_func_plus_t
{
	void operator() (segment_tree_node<llong, delta>* root, llong x) const
	{
		root->mark().plus=(root->mark().plus+x)%p;
		root->data()=(root->data()+x*root->segment())%p;
	}
};

struct mod_func_mul_t
{
	void operator() (segment_tree_node<llong, delta>* root, llong x) const
	{
		root->data()=(root->data()*x)%p;
		root->mark().plus=(root->mark().plus*x)%p;
		root->mark().mul=(root->mark().mul*x)%p;
	}
};

vector<llong> v;
segment_tree<llong, delta, data_func_t> stree;

int main()
{
	llong i, f, x, y, k;
	cin >> n >> m >> p;
	v.resize(n);
	
	for (i=0; i<n; i++)
		cin >> v[i];
	
	stree.construct(0, n, v);
	
	for (i=0; i<m; i++)
	{
		cin >> f;
		
		if (f==1)
		{
			cin >> x >> y >> k;
			stree.modify(--x, y, k, mod_func_mul_t(), search_func_t());
		}
		else if (f==2)
		{
			cin >> x >> y >> k;
			stree.modify(--x, y, k, mod_func_plus_t(), search_func_t());
		}
		else
		{
			cin >> x >> y;
			cout << stree.search(--x, y, search_func_t()) << endl;
		}
	}
	
	return 0;
}
