#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000010;
int n,m,rt,p;
int cnt,idx;
int av[N],size[N],dep[N],fa[N],zl[N],son[N],pos[N],val[N];
int to[N],nxt[N],head[N];
int f,x,y,v;
int ls[N],rs[N];
long long sum[N],add[N];
inline int read(){
    char c=',';int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x;
}
inline void insert(int a,int b){
    to[++cnt]=b,nxt[cnt]=head[a],head[a]=cnt;
    to[++cnt]=a,nxt[cnt]=head[b],head[b]=cnt;
}
void dfs1(int u){
    size[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa[u])continue;
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs1(v);
        if(!son[u]||size[v]>size[son[u]])son[u]=v;
        size[u]+=size[v];
    }
}
void dfs2(int u,int chain){
    pos[u]=++idx;val[idx]=u;zl[u]=chain;
    if(!son[u])return;
    dfs2(son[u],chain);
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(dep[v]>dep[u]&&v!=son[u])dfs2(v,v);
    }
}
void build(int k,int l,int r){
    ls[k]=l,rs[k]=r,sum[k]=0,add[k]=0;
    if(l==r){
        sum[k]=av[val[l]];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
    sum[k]=(sum[k<<1]+sum[k<<1|1])%p;
}
void pd(int k){
    if(add[k]){
        long long ad=add[k];
        add[k<<1]+=ad;
        add[k<<1|1]+=ad;
        sum[k<<1]+=(rs[k<<1]-ls[k<<1]+1)*ad;sum[k<<1]%=p;
        sum[k<<1|1]+=(rs[k<<1|1]-ls[k<<1|1]+1)*ad;sum[k<<1|1]%=p;
        add[k]=0;
    }
}
void queryadd(int k,int x,int y,int v){
    int l=ls[k],r=rs[k],mid=l+r>>1;
    if(l==x&&r==y){
        sum[k]+=(r-l+1)*v;
        add[k]+=v;
        pd(k);
        return;
    }
    pd(k);
    if(x>mid)queryadd(k<<1|1,x,y,v);
    else if(y<=mid)queryadd(k<<1,x,y,v);
    else queryadd(k<<1,x,mid,v),queryadd(k<<1|1,mid+1,y,v);
    sum[k]=(sum[k<<1]+sum[k<<1|1])%p;
}
long long querysum(int k,int x,int y){
    int l=ls[k],r=rs[k],mid=l+r>>1;
    if(l==x&&r==y){
        return sum[k];
    }
    pd(k);
    if(x>mid)return querysum(k<<1|1,x,y);
    else if(y<=mid)return querysum(k<<1,x,y);
    else return (querysum(k<<1,x,mid)+querysum(k<<1|1,mid+1,y))%p;
}
void solveadd1(int x,int y,int v){
    while(zl[x]!=zl[y]){
        if(dep[zl[x]]<dep[zl[y]])swap(x,y);
        queryadd(1,pos[zl[x]],pos[x],v);
        x=fa[zl[x]];
    }
    if(pos[x]>pos[y])swap(x,y);
    queryadd(1,pos[x],pos[y],v);
    return;
}
long long solvesum1(int x,int y){
    long long sum=0;
    while(zl[x]!=zl[y]){
        if(dep[zl[x]]<dep[zl[y]])swap(x,y);
        sum+=querysum(1,pos[zl[x]],pos[x]);
        sum%=p;
        x=fa[zl[x]];
    }
    if(pos[x]>pos[y])swap(x,y);
    sum+=querysum(1,pos[x],pos[y]);
    sum%=p;
    return sum;
}
int main(){
    n=read();m=read();rt=read();p=read();
    for(int i=1;i<=n;i++)av[i]=read();
    for(int i=1;i<n;i++){
        x=read();y=read();
        insert(x,y);
    }
    dfs1(rt);dfs2(rt,rt);
    build(1,1,n);
    while(m--){
        f=read();
        if(f==1){
            x=read();y=read();v=read();
            solveadd1(x,y,v%p);
        }
        else if(f==2){
            x=read();y=read();
            printf("%lld\n",solvesum1(x,y));
        }
        else if(f==3){
            x=read();v=read();
            queryadd(1,pos[x],pos[x]+size[x]-1,v);
        }
        else if(f==4){
            x=read();
            printf("%lld\n",querysum(1,pos[x],pos[x]+size[x]-1)%p);
        }
    }
    return 0;
}
