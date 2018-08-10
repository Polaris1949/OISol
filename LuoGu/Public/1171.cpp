#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=2e9,a[41][41],l[41],tot,sum,to[41];
void search(int now,int xx){
    if(xx==n){
        ans=min(a[now][1]+tot,ans);
        return;
    }    
    for(int i=1;i+xx<=n;i++)
        if(tot+sum+a[now][to[i]]-l[now]<ans){
            tot+=a[now][to[i]];
            sum-=l[now];
            swap(to[i],to[n-xx]);
            search(to[n-xx],xx+1);
            swap(to[i],to[n-xx]);
            sum+=l[now];
            tot-=a[now][to[i]];
        }
}
int main()
{
    //ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        l[i]=2e9;to[i]=i; 
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(j!=i)    l[i]=min(a[i][j],l[i]); 
        }
        sum+=l[i];
    }
    swap(to[n],to[1]);search(1,1);
    cout<<ans;
    return 0;
}
