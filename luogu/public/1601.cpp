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
	}
	
	~integer() noexcept = default;
	
	integer operator + (const integer& __x) const
	{
		integer ret;
		bool comp=this->_M_dataplus.size()<__x._M_dataplus.size();
		int mins=comp?this->_M_dataplus.size():__x._M_dataplus.size(),
			maxs=comp?__x._M_dataplus.size():this->_M_dataplus.size();
		ret._M_dataplus.resize(maxs+1);
		
		for (int i=0; i<mins; i++)
		{
			ret._M_dataplus[i]+=this->_M_dataplus[i]+__x._M_dataplus[i];
			ret._M_dataplus[i+1]+=ret._M_dataplus[i]/10;
			ret._M_dataplus[i]%=10;
		}
		
		for (int i=mins; i<maxs; i++)
		{
			ret._M_dataplus[i]+=comp?__x._M_dataplus[i]:this->_M_dataplus[i];
			ret._M_dataplus[i+1]+=ret._M_dataplus[i]/10;
			ret._M_dataplus[i]%=10;
		}
		
		if (ret._M_dataplus.back()==0) ret._M_dataplus.pop_back();
		return ret;
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
		for (int i=__x._M_dataplus.size()-1; i>=0; i--)
			__out << short(__x._M_dataplus[i]);
		
		return __out;
	}
};

integer a, b;

int main()
{
	cin >> a >> b;
	cout << a+b << endl;
	return 0;
}
