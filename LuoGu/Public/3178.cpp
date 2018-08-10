#include <iostream>
#include <cstring>
using namespace std;

long long n, q, cnt, v[200005], w[200005];

class segment_tree
{
		struct node
		{
			long long data, mark;
		};

	public:
		void push_up(long long p)
		{
			t[p].data=t[p<<1].data+t[p<<1|1].data;
		}

		void push_down(long long p, long long x)
		{
			if (t[p].mark)
			{
				t[p<<1].mark+=t[p].mark;
				t[p<<1|1].mark+=t[p].mark;

				t[p<<1].data+=t[p].mark*(x-x/2);
				t[p<<1|1].data+=t[p].mark*(x/2);

				t[p].mark=0;
			}
		}

		void construct(long long p, long long l, long long r);
		void modify(long long p, long long l, long long r, long long x, long long y, long long cnt);
		long long find(long long p, long long l, long long r, long long x, long long y);

	private:
		node t[800005];
} st;

void segment_tree::construct(long long p, long long l, long long r)
{
	if (l==r)
	{
		t[p].data=w[l];
		t[p].mark=0;
		return;
	}

	long long mid=(l+r)>>1;
	construct(p<<1, l, mid);
	construct(p<<1|1, mid+1, r);
	push_up(p);
}

void segment_tree::modify(long long p, long long l, long long r, long long x, long long y, long long cnt)
{
	if (y<l || x>r) return;

	if (x<=l && y>=r)
	{
		t[p].data+=cnt*(r-l+1);
		t[p].mark+=cnt;
		return;
	}

	push_down(p, r-l+1);

	long long mid=(l+r)>>1;
	modify(p<<1, l, mid, x, y, cnt);
	modify(p<<1|1, mid+1, r, x, y, cnt);
	push_up(p);
}

long long segment_tree::find(long long p, long long l, long long r, long long x, long long y)
{
	if (y<l || x>r)  return 0 ;
	if (x<=l && y>=r) return t[p].data;
	push_down(p, r-l+1);

	long long mid=(l+r)>>1;
	return (find(p<<1, l, mid, x, y)+find(p<<1|1, mid+1, r, x, y));
}

struct gnode
{
	long long to, nxt;
} edge[200005];

class graph
{
	public:
		graph()
		{
			memset(head, -1, sizeof(head));
			fa[1]=0;
			depth[0]=-1;
		}

		void insert(long long u, long long v);
		void con_tree(long long u);
		void con_link(long long u, long long topn);
		void mod_path(long long u, long long v, long long cnt);
		long long find_path(long long u, long long v);
		long long find_path(long long u);
		void mod_node(long long x, long long cnt);
		void mod_subt(long long x, long long cnt);
		long long find_subt(long long x);

	private:
		long long head[200005], tot, fa[200005], size[200005], depth[200005],
		    cnt, id[200005], sz[200005], son[200005], top[200005];
} g;

void graph::insert(long long u, long long v)
{
	edge[tot]={v, head[u]};
	head[u]=tot++;
}

void graph::con_tree(long long u)
{
	depth[u]=depth[fa[u]]+1, sz[u]=1;

	for (long long i=head[u]; ~i; i=edge[i].nxt)
	{
		long long v=edge[i].to;
		if (!fa[v] && v!=fa[u])
		{
			fa[v]=u;
			con_tree(v);
			sz[u]+=sz[v];
			if (sz[son[u]]<sz[v]) son[u]=v;
		}
	}
}

void graph::con_link(long long u, long long topn)
{
	id[u]=++cnt;
	w[cnt]=v[u];
	top[u]=topn;
	if (!son[u]) return;

	con_link(son[u], topn);

	for (long long i=head[u]; ~i; i=edge[i].nxt)
	{
		long long v=edge[i].to;
		if (v!=fa[u] && v!=son[u]) con_link(v, v);
	}
}

void graph::mod_node(long long x, long long cnt)
{
	st.modify(1, 1, n, id[x], id[x], cnt);
}

void graph::mod_subt(long long x, long long cnt)
{
	st.modify(1, 1, n, id[x], id[x]+sz[x]-1, cnt);
}

long long graph::find_subt(long long x)
{
	return st.find(1, 1, n, id[x], id[x]+sz[x]-1);
}

void graph::mod_path(long long u, long long v, long long cnt)
{
	while (top[u]!=top[v])
		if (depth[top[u]]>depth[top[v]])
		{
			st.modify(1, 1, n, id[top[u]], id[u], cnt);
			u=fa[top[u]];
		}
		else
		{
			st.modify(1, 1, n, id[top[v]], id[v], cnt);
			v=fa[top[v]];
		}

	if (depth[u]<depth[v])
		st.modify(1, 1, n, id[u], id[v], cnt);
	else
		st.modify(1, 1, n, id[v], id[u], cnt);
}

long long graph::find_path(long long u, long long v)
{
	long long ans=0;

	while (top[u]!=top[v])
	{
		if (depth[top[u]]>depth[top[v]])
		{
			ans+=st.find(1, 1, n, id[top[u]], id[u]);
			u=fa[top[u]];
		}
		else
		{
			ans+=st.find(1, 1, n, id[top[v]], id[v]);
			v=fa[top[v]];
		}
	}

	if (depth[u]<depth[v])
		ans+=st.find(1, 1, n, id[u], id[v]);
	else
		ans+=st.find(1, 1, n, id[v], id[u]);

	return ans;
}

long long graph::find_path(long long u)
{
	long long ans=0;
	
	while (top[u]!=1)
	{
		ans+=st.find(1, 1, n, id[top[u]], id[u]);
		u=fa[top[u]];
	}
	
	ans+=st.find(1, 1, n, id[1], id[u]);
	return ans;
}

int main()
{
	long long i, o, x, y;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;

	for (long long i=1; i<=n; ++i)
		cin >> v[i];

	for (long long i=1; i<n; ++i)
	{
		cin >> x >> y;
		g.insert(x, y);
		g.insert(y, x);
	}

	g.con_tree(1);
	g.con_link(1, 1);
	st.construct(1, 1, n);

	for (i=1; i<=q; ++i)
	{
		cin >> o;

		if (o==1)
		{
			cin >> x >> y;
			g.mod_node(x, y);
		}
		else if (o==2)
		{
			cin >> x >> y;
			g.mod_subt(x, y);
		}
		else
		{
			cin >> x;
			cout << g.find_path(x) << '\n';
		}
	}

	return 0;
}
