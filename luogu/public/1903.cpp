#include <cstring>
#include <iostream>
using namespace std;

int n, m, a[10010];
bool b[10010];

int main()
{
	int i, j, x, y, s;
	char op;
	cin >> n >> m;

	for (i=0; i<n; ++i)
		cin >> a[i];

	for (i=0; i<m; ++i)
	{
		cin >> op >> x >> y;
		--x;

		if (op=='Q')
		{
			s=0;
			memset(b, false, sizeof(b));

			for (j=x; j<y; ++j)
				if (!b[a[j]])
				{
					b[a[j]]=true;
					++s;
				}

			cout << s << endl;
		}
		else a[x]=y;
	}

	return 0;
}
