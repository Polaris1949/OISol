#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	int x,v;
} q[500005];

int n,d,k;
int x[500005],s[500005],f[500005];

bool check(int g)
{
	int qmin=d-g,qmax=d+g;
	int head=0,tail=-1,cur=0;
	
	if(qmin<=0) qmin=1;
	memset(f,0,sizeof(f));
	
	for(int i=1; i<=n; i++)
	{
		for(; (cur<i)&&(x[cur]<=x[i]-qmin); cur++)
		{

			while((head<=tail)&&(q[tail].v<f[cur])) tail--;


			if(f[cur]<=-1000000000) continue;
			q[++tail].v=f[cur];
			q[tail].x=x[cur];
		}
		
		while((head<=tail)&&(x[i]-q[head].x>qmax)) head++;
		f[i]=(head<=tail)? q[head].v+s[i]:-1000000000;
		if(f[i]>=k) return true;
	}
	
	return false;
}

int main()
{
	cin>>n>>d>>k;
	
	for(int i=1; i<=n; i++)
		cin>>x[i]>>s[i];
	
	int l=0,r=x[n],ans=-1;
	int m=(l+r)/2;
	
	for(; l<=r; m=(l+r)/2)
		if(check(m)) r=m-1,ans=m;
		else l=m+1;
	
	cout<<ans<<endl;
	return 0;
}
