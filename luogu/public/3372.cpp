#include <vector>
#include <iostream>
#include <algorithm>
#include <polaris/segment_tree>
using namespace std;
using namespace polaris;

typedef long long llong;

struct fsum_t
{
	llong operator() (llong x, llong y) const
	{
		return x+y;
	}
};

struct fmod_t
{
	void operator() (segment_tree_node<llong, llong>* root, llong x) const
	{
		root->data()+=root->segment()*x;
		root->mark()+=x;
	}
};

llong n, m;
vector<llong> v;
segment_tree<llong, llong, fsum_t> stree;

int main()
{
	llong i, x, y, k, f;
	cin >> n >> m;
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
			stree.modify(--x, y, k, fmod_t(), fmod_t());
		}
		else
		{
			cin >> x >> y;
			cout << stree.search(--x, y, fmod_t()) << endl;
		}
	}
	
	return 0;
}
