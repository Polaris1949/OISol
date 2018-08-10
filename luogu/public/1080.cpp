#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class integer
{
	vector<char> _M_dataplus;
	
public:
	integer()
		: _M_dataplus()
	{
		this->_M_dataplus.push_back(0);
	}
	
	integer(int __x)
		: _M_dataplus()
	{
		this->_M_dataplus.clear();
		
		if (__x == 0)
		{
			this->_M_dataplus.push_back(0);
			return;
		}
		
		while (__x > 0)
		{
			this->_M_dataplus.push_back(__x % 10);
			__x /= 10;
		}
	}
	
	~integer() noexcept = default;
	
	integer& operator = (int __x)
	{
		return (*this = integer(__x));
	}
	
	integer& operator = (const integer& __x) = default;
	
	integer operator * (const integer& __x) const
	{
		integer ret;
		ret._M_dataplus.resize(this->_M_dataplus.size()
			+__x._M_dataplus.size());
		
		for (int i=0; i<this->_M_dataplus.size(); i++)
			for (int j=0; j<__x._M_dataplus.size(); j++)
			{
				ret._M_dataplus[i+j]+=this->_M_dataplus[i]
					*__x._M_dataplus[j];
				ret._M_dataplus[i+j+1]+=ret._M_dataplus[i+j]/10;
				ret._M_dataplus[i+j]%=10;
			}
		
		while (ret._M_dataplus.back()==0 && ret._M_dataplus.size()>1)
			ret._M_dataplus.pop_back();
		
		return ret;
	}
	
	integer& operator *= (const integer& __x)
	{
		return ((*this) = (*this) * __x);
	}
	
	integer operator / (int __x) const
	{
		if (__x == 0) throw;
		
		integer ret;
		ret._M_dataplus.resize(this->_M_dataplus.size());
		int t=0;
		
		for (int i=this->_M_dataplus.size()-1; i>=0; i--)
		{
            t=t*10+this->_M_dataplus[i];
            ret._M_dataplus[i]=t/__x;
            t%=__x;
        }
        
        while (ret._M_dataplus.back()==0 && ret._M_dataplus.size()>1)
        	ret._M_dataplus.pop_back();
        
        return ret;
	}
	
	bool operator < (const integer& __x) const
	{
		if (this->_M_dataplus.size()<__x._M_dataplus.size())
			return true;
		if (this->_M_dataplus.size()>__x._M_dataplus.size())
			return false;
		
		bool e=true;
		
		for (int i=this->_M_dataplus.size()-1; i>=0; i--)
			if (this->_M_dataplus[i]>__x._M_dataplus[i]) return false;
			else if (this->_M_dataplus[i]<__x._M_dataplus[i]) e=false;
		
		return !e;
	}
	
	bool operator > (const integer& __x) const
	{
		return !(*this<__x);
	}
	
	friend ostream& operator << (ostream& __out, const integer& __x)
	{
		for (int i=__x._M_dataplus.size()-1; i>=0; i--)
			__out << short(__x._M_dataplus[i]);
		
		return __out;
	}
};

typedef long long llong;

struct node
{
	int a, b;
	llong p;
	
	bool operator < (const node& __x) const
	{
		return this->p<__x.p;
	}
	
	friend istream& operator >> (istream& __in, node& __x)
	{
		__in >> __x.a >> __x.b;
		__x.p=llong(__x.a)*llong(__x.b);
		return __in;
	}
};

int n, x, y;
vector<node> v;

int main()
{
	int i;
	integer t, now, ans;
	cin >> n >> x >> y;
	v.resize(n);
	
	for (i=0; i<n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	now=x;
	
	for (i=0; i<n; i++)
	{
		t=now/v[i].b;
		if (t>ans) ans=t;
		now*=v[i].a;
	}
	
	cout << ans << endl;
	return 0;
}
