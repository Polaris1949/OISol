#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

struct p
{
	int i, t;
};

int n, b[1000];
p a[1000];

bool comp(const p& x, const p& y)
{
	return x.t<y.t;
}

int main()
{
	int i, j;
	double ans=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		a[i].i=i;
		cin >> a[i].t;
	}
	
	sort(a, a+n, comp);
	
	for (i=0; i<n; i++)
	{
		if (i!=0) cout << ' ';
		cout << a[i].i+1;
		
		for (j=i; j<n; j++)
			b[j]+=a[i].t;
		
		b[i]-=a[i].t;
	}
	
	for (i=0; i<n; i++)
		ans+=b[i];
	
	ans/=n;
	cout << endl << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
	return 0;
}
