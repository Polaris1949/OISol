#include <iostream>
#include <cctype>
using namespace std;

long long f[10][101][600];
long long maxv, ans;
int n, k;

inline int getlen(long long x)
{
	int ans=0;
	bool s;
	
	while (x)
	{
		if (x&1) ans++;
		x>>=1;
	}
	
	return ans;
}

inline bool check(long long x, long long y)
{
	if (x&y) return true;
	if ((x>>1)&y) return true;
	if ((x<<1)&y) return true;

	return false;
}

int main()
{
	int i, j, l, len, o;
	cin >> n >> k;
	maxv=(1<<n)-1;
	f[0][0][0]=1;
	
	for (i=1; i<=n; i++)
		for (j=0; j<=k; j++)
			for (l=0; l<=maxv; l++)
			{
				len=getlen(l);
				
				if (len>j) continue;
				if (l&(l>>1)) continue;
				
				for (o=0; o<=maxv; o++)
				{
					if (check(o,l)) continue;
					if (o&(o>>1)) continue;
					
					f[i][j][l]+=f[i-1][j-len][o];
				}
			}
	
	for (i=0; i<=maxv; i++)
		ans+=f[n][k][i];
	
	cout << ans << endl;
	return 0;
}
