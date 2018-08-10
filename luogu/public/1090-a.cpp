#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	int i, x, s, ans=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		q.push(x);
	}
	
	for (i=0; i<n-1; i++)
	{
		s=q.top(); q.pop();
		s+=q.top(); q.pop();
		ans+=s;
		q.push(s);
	}
	
	cout << ans << endl;
	return 0;
}
