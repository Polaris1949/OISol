#include <iostream>
using namespace std;

int n, m;
int t[500001];

void add(int x, int k)
{
	while (x<=n)
	{
		t[x]+=k;
		x+=x&-x;
	}
}

int sum(int x)
{
	int ret=0;

	while (x)
	{
		ret+=t[x];
		x-=x&-x;
	}

	return ret;
}

int main()
{
	int i, o, x, y;
	cin >> n >> m;

	for (i=1; i<=n; ++i)
	{
		cin >> x;
		add(i, x);
	}

	for (i=1; i<=m; ++i)
	{
		cin >> o >> x >> y;

		if (o==1) add(x, y);
		else cout << sum(y)-sum(x-1) << endl;
	}

	return 0;
}
