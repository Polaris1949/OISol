#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int a[15005],b[15005],c[15005],d[15005],w[15005];
int h[40005];
int f[15005];
int n,m,k,t,x,y,z,p,q;

int main()
{
	//freopen("magic.in","r",stdin);
    //freopen("magic.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
	{
        cin>>h[i]; //魔法值
        w[h[i]]++; //魔法值个数
    }
    for(int i=1;i<=n/9;i++)     //i: d-c
	{
        x=1+9*i;           // x: d-a
y=0;
        for(int j=2+9*i;j<=n;j++)    //j: d
		{
            y=y+w[(j-x)]*w[j-x+i+i];  //w[j-x]: a的魔法值个数 w[j-x+i+i]: a+2*(d-c)的魔法值个数
            d[j]=d[j]+y*w[j-i];
            c[j-i]=c[j-i]+y*w[j];
        }
        x=8*i+1;y=0;
        for(int j=n-9*i-1;j>=1;j--)
		{
            y=y+w[j+x]*w[j+x+i];
            a[j]=a[j]+y*w[j+i+i];
            b[j+i+i]=b[j+i+i]+y*w[j];
        }
    }
    for(int i=1;i<=m;i++)cout<<a[h[i]]<<" "<<b[h[i]]<<" "<<c[h[i]]<<" "<<d[h[i]]<<endl;
    return 0;
}
