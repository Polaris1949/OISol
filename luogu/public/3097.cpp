#include <iostream>
#include <vector>
#include <polaris/segment_tree>
using namespace std;
using namespace polaris;

int n, d;

struct node
{
	int pp, pb, bp, bb;
	
	node()
		: pp(), pb(), bp(), bb()
	{
	}
	
	node(int bb)
		: pp(), pb(), bp(), bb(bb)
	{
	}
	
	node(int pp, int pb, int bp, int bb)
		: pp(pp), pb(pb), bp(bp), bb(bb)
	{
	}
};

vector<node> v;

int r(segment_tree_node<node, void>* root, const node& x)
{
	root->data() = x;
}

class df
{
public:
	node operator()(const node& x, const node& y)
	{
		return node(max(x.pb+y.pp, x.pp+y.bp), max(x.pb+y.pb, x.pp+y.bb),
			max(x.bb+y.pp, x.bp+y.bp), max(x.bb+y.pb, x.bp+y.bb));
	}
};

int main()
{
	int i, x, a, b;
	long long ans=0;
	cin >> n >> d;
	
	for (i=0; i<n; ++i)
	{
		cin >> x;
		v.push_back(node(x));
	}
	
	segment_tree<node, void, df> st(0, n, v);
	
	for (i=0; i<d; ++i)
	{
		cin >> a >> b;
		--a;
		st.modify(a, b, r);
		ans+=st.root()->data().bb;
	}
	
	cout << ans << endl;
	return 0;
}
