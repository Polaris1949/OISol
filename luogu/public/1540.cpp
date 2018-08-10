#include <iostream>
#include <deque>
using namespace std;

int m, n;
deque<int> q;

int main()
{
	int i, j, x, s=0;
	bool f;
	cin >> m >> n;
	
	for (i=1; i<=n; i++)
	{
		cin >> x;
		f=false;
		
		for (j=0; j<q.size(); j++)
			if (q[j]==x)
			{
				f=true; break;
			}
		
		if (!f)
		{
			s++;
			if (q.size()==m) q.pop_front();
			q.push_back(x);
		}
	}
	
	cout << s << endl;
	return 0;
}
