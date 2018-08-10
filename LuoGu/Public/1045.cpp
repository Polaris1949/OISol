#include<bits/stdc++.h>
using namespace std;

struct integer
{
	static const int MAX=4000;
	short a[MAX+1];
	int Len;

	integer()
	{
		memset(a,0,sizeof(a));
		Len=1;
	}

	integer operator=(std::string N)
	{
		memset(a,0,sizeof(a));
		if(N[0]=='-')
		{
			Len=N.size()-1;
			a[0]=1;
			for(int i=1; i<=Len; ++i)
				a[i]=N[Len-i+1]-'0';
			return *this;
		}
		if(N[0]=='+')
		{
			Len=N.size()-1;
			a[0]=0;
			for(int i=1; i<=Len; ++i)
				a[i]=N[Len-i+1]-'0';
			return *this;
		}
		Len=N.size();
		for(int i=1; i<=Len; ++i)
			a[i]=N[Len-i]-'0';
		return *this;
	}

	integer operator=(const int & b)
	{
		char s[MAX+1];
		sprintf(s,"%d",b);
		*this=s;
		return *this;
	}

	integer(std::string N)
	{
		*this=N;
	}
	integer(const int &b)
	{
		*this=b;
	}

	int read()
	{
		char s[MAX+1];
		int t=scanf("%s",s);
		*this=s;
		return t;
	}

	void write()
	{
		int r,re=1,now=0;
		for(int i=Len; i>=1; --i)
		{
			cout<<a[i];
			++now;
			if(now%50==0)cout<<endl;
		}
	}

	integer operator*(integer x)
	{
		integer c;
		c.Len=Len+x.Len;
		for(int i=1; i<=Len; ++i)
		{
			for(int j=1; j<=x.Len; ++j)
			{
				c.a[i+j-1]+=a[i]*x.a[j];
				if(c.a[i+j-1]>=10)
				{
					c.a[i+j]+=c.a[i+j-1]/10;
					c.a[i+j-1]%=10;
				}
			}
		}
		c.Len=500;
		return c;
	}

} two,ans;

int p;

integer quick_power(int y)
{
	if(y==1)return two;
	if(y==0)return 1;
	integer re;
	if(y%2==0)
	{
		re=quick_power(y/2);
		re=re*re;
	}
	else
	{
		re=quick_power(y/2);
		re=re*re*two;
	}
	return re;
}

int main()
{
	two=2;
	cin>>p;
	cout<<(long long)(log10(2)*p+1)<<endl;
	ans=quick_power(p);
	ans.a[1]-=1;
	ans.write();
	return 0;
}
