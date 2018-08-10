#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

struct bign
{
	int l;
	short int w[2000];
	bign()
	{
		l=1;
		memset(w,0,sizeof(w));
	}

	bign(int x)
	{
		l=0;
		memset(w,0,sizeof(w));
		while(x)
		{
			w[l]=x%10,x/=10;
			l++;
		}
	}

	bool operator >(bign x)
	{
		if(l>x.l)return 1;
		if(l==x.l)
		{
			for(int i=l-1; i>=0; i--)
			{
				if(w[i]<x.w[i])return 0;
				if(w[i]>x.w[i])return 1;
			}
		}
		return 0;
	}

	bign operator +(const bign& x)
	{
		bign ans;
		ans.l=max(l,x.l);

		for(int i=0; i<ans.l; i++)
		{
			ans.w[i]+=w[i]+x.w[i];
			ans.w[i+1]+=ans.w[i]/10;
			ans.w[i]%=10;
		}

		if(ans.w[ans.l])ans.l++;
		return ans;
	}

	bign operator *(const bign& x)
	{
		bign ans;
		ans.l=l+x.l;

		for(int i=0; i<l; i++)
		{
			for(int j=0; j<x.l; j++)
			{
				ans.w[i+j]+=w[i]*x.w[j];
				ans.w[i+j+1]+=ans.w[i+j]/10;
				ans.w[i+j]%=10;
			}
		}

		if(ans.w[ans.l-1]==0)ans.l--;
		return ans;
	}

	bign operator *(int x)
	{
		return (*this)*(bign(x));
	}

	void write()
	{
		if(l==0)printf("0");
		for(int i=l-1; i>=0; i--)printf("%d",w[i]);
		printf("\n");
	}
};

int n,m;
int a[85];
bign ans;
bign f[85][85];
bign tm[85];

int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);

	tm[0]=1;
	for(i=1; i<=m; i++)tm[i]=tm[i-1],tm[i]=tm[i]*2;

	ans=0;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)scanf("%d",&a[j]);

		for(j=1; j<=m; j++)f[j][j]=tm[m]*a[j];

		for(j=1; j<m; j++)
		{
			for(k=1; k<m; k++)
			{
				if(j+k>m)break;
				bign t1=tm[m-j]*a[k]+f[k+1][k+j];
				bign t2=tm[m-j]*a[k+j]+f[k][k+j-1];
				if(t1>t2)f[k][k+j]=t1;
				else f[k][k+j]=t2;
			}
		}

		ans=ans+f[1][m];
	}

	ans.write();
	return 0;
}
