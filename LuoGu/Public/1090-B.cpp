#include <iostream>
#include <set>
using namespace std;

int n, ans;
multiset<int> s;

int main()
{
	int i, x;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		s.insert(x);
	}
	
	for (i=0; i<n-1; i++)
	{
		x=*s.begin(); s.erase(s.begin());
		x+=*s.begin(); s.erase(s.begin());
		ans+=x;
		s.insert(x);
	}
	
	cout << ans << endl;
	return 0;
}
