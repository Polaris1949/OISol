#include <iostream>
#include <string>
using namespace std;

const int mod=1000000007;
int n, m, k;
int f[2][1000][1000], t[2][1000][1000];
string a, b;

int aread(int p[][1000][1000], int x, int i, int j)
{
	return (i<0&&j<0?1:(i>=0&&j>=0?p[x][i][j]:0));
}

void awrite(int p[][1000][1000], int x, int i, int j, int v)
{
	if (i>=0&&j>=0) p[x][i][j]=v;
}

int main()
{
	int i, j, p, cur=1;
	cin >> n >> m >> k;
	cin >> a >> b;
	
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; j++)
			for (p=0; p<k; p++)
			{
				if (a[i]==b[j]) 
					awrite(t, cur, j, p, (aread(t, 1-cur, j-1, p) \
						+aread(f, 1-cur, j-1, p-1))%mod);
				else
					awrite(t, cur, j, p, 0);
				
				awrite(f, cur, j, p, (aread(f, 1-cur, j, p) \
					+aread(t, cur, j, p))%mod); 
			}
		
		cur^=1;
	}
	
	cout << aread(f, 1-cur, m-1, k-1) << endl;
	return 0;
}
