#include <iostream>
#include <vector>
using namespace std;

class integer
{
	bool _M_negative;
	vector<char> _M_dataplus;
	
public:
	integer()
		: _M_negative(), _M_dataplus()
	{
	}
	
	~integer() noexcept = default;
	
	integer operator - (const integer& __x) const
	{
		const integer *m, *s;
		integer ret;
		
		if (*this<__x)
		{
			ret._M_negative=true;
			m=&__x;
			s=this;
		}
		else
		{
			ret._M_negative=false;
			m=this;
			s=&__x;
		}
		
		int mins=s->_M_dataplus.size(),
			maxs=m->_M_dataplus.size();
		ret._M_dataplus.resize(maxs);
		
		for (int i=0; i<mins; i++)
		{
			ret._M_dataplus[i]+=m->_M_dataplus[i]-s->_M_dataplus[i];
			
			if (ret._M_dataplus[i]<0)
			{
				ret._M_dataplus[i]+=10;
				ret._M_dataplus[i+1]--;
			}
		}
		
		for (int i=mins; i<maxs; i++)
		{
			ret._M_dataplus[i]+=m->_M_dataplus[i];
			
			if (ret._M_dataplus[i]<0 && i<maxs-1)
			{
				ret._M_dataplus[i]+=10;
				ret._M_dataplus[i+1]--;
			}
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
	
	friend istream& operator >> (istream& __in, integer& __x)
	{
		string temp;
		__in >> temp;
		
		for (int i=temp.size()-1; i>=0; i--)
			__x._M_dataplus.push_back(temp[i]-'0');
		
		return __in;
	}
	
	friend ostream& operator << (ostream& __out, const integer& __x)
	{
		if (__x._M_negative) __out << '-';
		
		for (int i=__x._M_dataplus.size()-1; i>=0; i--)
			__out << short(__x._M_dataplus[i]);
		
		return __out;
	}
};

integer a, b;

int main()
{
	cin >> a >> b;
	cout << a-b << endl;
	return 0;
}
