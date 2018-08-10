#include <iostream>
#include <string>
using namespace std;

int n, d[10], p[500];
bool g[10][10];
string s;

int main()
{
	int i, j, k, x, y, z;
	cin >> s >> n;

	for (i=0; i<n; ++i)
	{
		cin >> x >> y;
		g[x][y]=true;
	}

	for (k=0; k<10; ++k)
		for (i=0; i<10; ++i)
			for (j=0; j<10; ++j)
				if (g[i][k]&&g[k][j]) g[i][j]=true;

	for (i=0; i<10; ++i)
	{
		g[i][i]=true;

		for (j=0; j<10; ++j)
			if (g[i][j]) ++d[i];
	}

	p[0]=1;

	for (i=0; s[i]; ++i)
	{
		z=0;
		x=d[s[i]-'0'];

		for (j=0; j<500; ++j)
		{
			p[j]=(p[j]*x+z);
			z=p[j]/10;
			p[j]%=10;
		}
	}

	i=499;
	while (p[i]==0) --i;

	for (; i>=0; --i)
		cout << p[i];

	cout << endl;
	return 0;
}
