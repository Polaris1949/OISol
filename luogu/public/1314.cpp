#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m;
long long s;
long long av[200010],an[200010];
struct st
{
    long long w,v;
}stone[200010];
struct ra
{
    long long l,r;
}range[200010];
int main()
{
    cin>>n>>m>>s;
    long long right=-1;
    for(long long i=1;i<=n;i++)
    {
        cin>>stone[i].w>>stone[i].v;
        right=stone[i].w>right?stone[i].w:right;
    }
    for(long long i=1;i<=m;i++)
        cin>>range[i].l>>range[i].r;
    long long left=0;
    long long minn=-1,p;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        av[0]=0,an[0]=0;
        for(long long i=1;i<=n;i++)
        {
            if(stone[i].w>=mid)
            {
                av[i]=av[i-1]+stone[i].v;
                an[i]=an[i-1]+1;
            }
            else 
            {
                av[i]=av[i-1];an[i]=an[i-1];    
            }
        }
        long long p=0;
        for(long long i=1;i<=m;i++)
        {
            p+=(av[range[i].r]-av[range[i].l-1])*(an[range[i].r]-an[range[i].l-1]);    
        }
        if(minn==-1 || minn>abs(p-s)) minn=abs(p-s);
        if(p<s)right=mid-1;
        else left=mid+1;
    }
    cout<<minn;
    return 0;
}
