#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> q;

int main()
{
	int i, j=1;
	cin >> n >> m;
	
	for (i=1; i<=n; i++)
		q.push(i);
	
	while (!q.empty())
	{
		if (j==m)
		{
			cout << q.front() << ' ';
			q.pop(); j=1;
		}
		
		q.push(q.front());
		q.pop();
		j++;
	}
	
	cout << endl;
	return 0;
}
