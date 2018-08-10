#include <iostream>
using namespace std;

int n, m;
char a[100][100];

int main()
{
	int i, j, p, q, s;
	cin >> n >> m;

	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cin >> a[i][j];

	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			if (a[i][j]=='*') cout << '*';
			else if (a[i][j]=='?')
			{
				s=0;

				for (p=(i-1>=0?i-1:0); p<=(i+1<n?i+1:n-1); p++)
					for (q=(j-1>=0?j-1:0); q<=(j+1<m?j+1:m-1); q++)
					{
						if (p==i && q==j) continue;
						if (a[p][q]=='*') s++;
					}

				cout << s;
			}

		cout << endl;
	}

	return 0;
}
