#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	int n, i, op, x;
	scanf("%d", &n);

	for (i=0; i<n; i++)
	{
		scanf("%d", &op);

		if (op==1)
		{
			scanf("%d", &x);
			q.push(x);
		}
		else if (op==2)
			printf("%d\n", q.top());
		else
			q.pop();
	}

	return 0;
}
