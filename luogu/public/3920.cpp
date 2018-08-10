#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
inline int read()
{
    char ch;
    int res=0;
    while(ch=getchar(),ch<'0'||ch>'9');
    res=ch-48;
    while(ch=getchar(),ch>='0'&&ch<='9')
    res=(res<<3)+(res<<1)+ch-48;
    return res;
} 
inline void put(long long x)
{
    if(x>9)put(x/10);
    putchar(x%10+48);
}
const double alpha=0.777666;
const int e=1e5+5,mod=1e9,inf=0x3f3f3f3f;
int test,n,r[e],fa[e],sze[e],son[e],num,next[e<<1],head[e],go[e<<1],cost[e<<1];
int dist[e];
long long ans=0;
bool vis[e];
vector<int>anc[e],id[e],sons[e];
inline void add(int x,int y,int v)
{
    next[++num]=head[x]; 
    head[x]=num;
    go[num]=y;
    cost[num]=v;
    next[++num]=head[y];
    head[y]=num;
    go[num]=x;
    cost[num]=v;
}
struct node
{
    node *lc,*rc; 
    int val,sze,pos;
    inline void reset(int v) 
    {
        lc=rc=NULL;
        val=v;
        sze=1;
        pos=rand();
    }
    inline void update() 
    {
        sze=(lc?lc->sze:0)+(rc?rc->sze:0)+1;
    }
}*rt_self[e],*rt_fa[e],used[4000006],*unused[4000006],*pool=used,**top=unused;

inline node* new_node(int val)
{
    node *res=(top!=unused)? *--top:pool++;
    res->reset(val);
    return res;
}
inline void del_node(node *&u)
{
    if(!u)return;
    *top++=u;
    if(u->lc)del_node(u->lc);
    if(u->rc)del_node(u->rc);
    u=NULL;
}
inline void zig(node *&u)
{
    node *v=u->lc;
    u->lc=v->rc;
    v->rc=u;
    v->sze=u->sze;
    u->update();
    u=v;
}
inline void zag(node *&u)
{
    node *v=u->rc;
    u->rc=v->lc;
    v->lc=u;
    v->sze=u->sze;
    u->update();
    u=v;
}
inline void insert(node *&u,int val)
{
    if(!u)
    {
        u=new_node(val);
        return;
    }
    ++u->sze;
    if(val<=u->val)
    {
        insert(u->lc,val);
        if(u->lc->pos<u->pos)zig(u);
    }
    else
    {
        insert(u->rc,val);
        if(u->rc->pos<u->pos)zag(u);
    }
}
inline int qrank(node *u,int val)
{
    if(!u)return 0;
    if(val<u->val)return qrank(u->lc,val);
    else return (u->lc?u->lc->sze:0)+1+qrank(u->rc,val);
}
inline int calc_grav(int &st)
{
    static int qn,que[e];
    que[qn=1]=st;
    fa[st]=0;
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        sze[u]=1;
        son[u]=0;
        for(int j=head[u];j;j=next[j])
        {
            int v=go[j];
            if(!vis[v]||v==fa[u])continue;
            fa[v]=u;
            que[++qn]=v;
        }
    }
    for(int i=qn;i>=2;i--)
    {
        int u=que[i],v=fa[u];
        sze[v]+=sze[u];
        if(sze[u]>son[v])
        son[v]=sze[u];
    }
    int all=sze[st],grav=0,min=inf;
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        if(all-sze[u]>son[u])
        son[u]=all-sze[u];
        if(son[u]<min)
        {
            min=son[u];
            grav=u;
        }
    }
    return grav;
}
inline int dac(int &st,int &par)
{
    static int qn,que[e];
    int grav=calc_grav(st);
    vis[grav]=false;
    que[qn=1]=grav;
    fa[grav]=0;
    dist[grav]=0;
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        for(int j=head[u];j;j=next[j])
        {
            int v=go[j];
            if(!vis[v]||v==fa[u])continue;
            fa[v]=u;
            dist[v]=dist[u]+cost[j];
            que[++qn]=v;
        }
    }
    for(int i=1;i<=qn;i++)
    {
        int u=que[i];
        id[u].push_back(grav);
        anc[u].push_back(dist[u]);
        sons[grav].push_back(u);
        insert(rt_self[grav],dist[u]-r[u]);
        if(par!=0)
        insert(rt_fa[grav],anc[u][anc[u].size()-2]-r[u]);
    }
    for(int i=head[grav];i;i=next[i])
    {
        int v=go[i];
        if(vis[v])dac(v,grav);
    }
}
inline void rebuild(int &u,int par)
{
    vector<int>tmpson=sons[u];
    int notres=anc[par].size();
    for(int i=0;i<tmpson.size();i++)
    {
        int v=tmpson[i];
        vis[v]=true;
        sons[v].clear();
        anc[v].resize(notres);
        id[v].resize(notres);
        del_node(rt_self[v]);
        del_node(rt_fa[v]);
    }
    dac(u,par);
}
inline void check(int &u)
{
    for(int i=0;i<anc[u].size();i++)
    {
        insert(rt_self[id[u][i]],anc[u][i]-r[u]);
        if(i!=0)
        insert(rt_fa[id[u][i]],anc[u][i-1]-r[u]);
    }
    for(int i=0;i<anc[u].size()-1;i++)
    {
        int sze_fa=rt_self[id[u][i]]->sze;
        int sze_son=rt_self[id[u][i+1]]->sze;
        if(sze_fa<=30)break;
        if(sze_son>alpha*sze_fa)
        {
            rebuild(id[u][i],i==0?0:id[u][i-1]);
            break;
        }
    }
}
inline int calc_ans(int &u,int &v,int &w)
{
    int res=0;
    anc[u]=anc[v];
    id[u]=id[v];
    anc[u].push_back(-w);
    id[u].push_back(u);
    for(int i=0;i<anc[u].size();i++)
    {
        anc[u][i]+=w;
        sons[id[u][i]].push_back(u);
        res+=qrank(rt_self[id[u][i]],r[u]-anc[u][i]);
        if(i!=0)
        res-=qrank(rt_fa[id[u][i]],r[u]-anc[u][i-1]);
    }
    return res;
}
int main()
{
    test=read();
    n=read();
    for(int i=1;i<=n;i++)
    {
        int fa_i=read(),c=read();
        r[i]=read();
        fa_i^=(ans%mod);
        if(i==1)
        {
            anc[i].push_back(0);
            id[i].push_back(i);
            sons[i].push_back(i);
            insert(rt_self[i],-r[i]);
            puts("0");
            continue;
        }
        add(fa_i,i,c);
        ans+=calc_ans(i,fa_i,c);
        check(i);
        put(ans);
        putchar('\n');
    }
    return 0;
}
