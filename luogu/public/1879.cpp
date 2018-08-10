#include <iostream>
using namespace std;

int m, n;
int st[2000];
bool w[2000][2000];
int map[2000];
int f[2000][2000];

int main()
{
	int i, j, k, v, x, ans=0;
	
	for (i=0; i<(1<<12); i++)
		if ((i&(i>>1))==0)
		{
			st[0]++;
			st[st[0]]=i;
		}
	
	for (i=1; i<=st[0]; i++)
		for (j=i; j<=st[0]; j++)
			if ((st[i]&st[j])==0)
			{
				w[i][j]=true;
				w[j][i]=true;
			}
	
	cin >> m >> n;
	
	for (i=1; i<=m; i++)
	{
		v=0;
		for (j=1; j<=n; j++)
		{
			cin >> x;
			v=v*2+x;
		}
		map[i]=v;
	}
	
	f[0][1]=1;
	
	for (i=1; i<=m; i++)
		for (j=1; j<=st[0]; j++)
			if ((st[j]|map[i])!=map[i])
				f[i][j]=-1;
			else
				for (k=1; k<=st[0]; k++)
					if (f[i-1][k]!=-1 && w[j][k])
						f[i][j]=(f[i][j]+f[i-1][k])%100000000;
	
	for (j=1; j<=st[0]; j++)
		if (f[m][j]!=-1)
			ans=(ans+f[m][j])%100000000;
	
	cout << ans << endl;
	return 0;
}
