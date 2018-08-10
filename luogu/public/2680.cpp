#include <cstring>
#include <iostream>
using namespace std;

constexpr int MAXN=3e5+10;

struct edge
{
    int nxt, to, dis;
};

struct length
{
    int len, lca, u, v;
};

edge e[MAXN*2],q[MAXN*2];

length len[MAXN];
int n, m, cnt, ans, num, ret, maxlen;
int head[MAXN], headq[MAXN], dis[MAXN], a[MAXN], s[MAXN], f[MAXN];
bool vis[MAXN];

inline void add_edge(int x,int y,int d)
{
    e[++cnt].nxt=head[x];
    e[cnt].to=y;
    e[cnt].dis=d;
    head[x]=cnt;
}

inline void add_que(int x, int y)
{
    q[++cnt].nxt=headq[x];
    q[cnt].to=y;
    headq[x]=cnt;
}

int find(int x)
{
    return f[x]==x?f[x]:f[x]=find(f[x]);
}

void dfs(int u, int pre)
{
    for (int i=head[u]; i; i=e[i].nxt)
    {
        int v=e[i].to;
        if (v==pre) continue;
        dfs(v,u);
        s[u]+=s[v];
    }

    if (s[u]==num&&a[u]>ret)
        ret=a[u];
}

inline bool check(int x)
{
    memset(s,0,sizeof(s));
    num=ret=0;
    for (int i=1;i<=m;i++)
        if (len[i].len>x)
        {
            s[len[i].u]++;
            s[len[i].v]++;
            s[len[i].lca]-=2;
            num++;
        }
    dfs(1,0);
    if(maxlen-ret>x)
        return false;
    return true;
}

void tarjan(int u, int pre)
{
    for (int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if (v==pre) continue;
        dis[v]=dis[u]+e[i].dis;
        tarjan(v,u);
        a[v]=e[i].dis;
        int f1=find(v);
        int f2=find(u);
        if(f1!=f2)
            f[f1]=find(f2);
        vis[v]=1;
    }

    for(int i=headq[u];i;i=q[i].nxt)
        if(vis[q[i].to])
        {
            int p=(i+1)>>1;
            len[p].lca=find(q[i].to);
            len[p].len=dis[u]+dis[q[i].to]-2*dis[len[p].lca];
            maxlen=max(maxlen,len[p].len);
        }
}

int main()
{
    int i, ax, bx, tx, x, y;
    cin >> n >> m;

    for (i=1; i<n; ++i)
    {
        cin >> ax >> bx >> tx;
        add_edge(ax, bx, tx);
        add_edge(bx, ax, tx);
    }

    for (i=1; i<=n; ++i)
        f[i]=i;

    cnt=0;

    for (i=1; i<=m; ++i)
    {
        cin >> x >> y;
        len[i].u=x;
        len[i].v=y;
        add_que(x,y);
        add_que(y,x);
    }

    tarjan(1,0);
    int l=0, r=maxlen, mid;

    while (l<=r)
    {
        mid=(l+r)>>1;

        if (check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }

    cout << ans << endl;
    return 0;
}
