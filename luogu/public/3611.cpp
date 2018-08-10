#include <iostream>
#include <queue>
using namespace std;

int n, t, a[10000];

bool ok(int mid)
{
	priority_queue<int, vector<int>, greater<int> > q;
	int i, x=0;
	
	for (i=0; i<n; i++)
	{
		if (q.size()==mid) {x=q.top(); q.pop();}
		if (x+a[i]>t) return false;
		q.push(x+a[i]);
	}
	
	return true;
}

int main()
{
	int i, l, r, mid;
	cin >> n >> t;
	
	for (i=0; i<n; i++)
		cin >> a[i];
	
	l=1; r=n;
	
	while (l!=r)
	{
		mid=(l+r)/2;
		
		if (ok(mid)) r=mid;
		else l=mid+1;
	}
	
	cout << l << endl;
	return 0;
}
