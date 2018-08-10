#include <iostream>
using namespace std;

int n, ans;
bool p[40000];
int phi[40000], f[40000];

int main()
{
	int i, j, x=0;
	cin >> n;

	if (n==1)
	{
		cout << '0' << endl;
		return 0;
	}

	for (i=2; i<n; ++i)
	{
		if (!p[i])
		{
			f[x++]=i;
			phi[i]=i-1;
		}

		for (j=0; j<x; ++j)
		{
			if (f[j]*i<=n)
			{
				p[f[j]*i]=true;

				if (i%f[j]==0)
				{
					phi[f[j]*i]=f[j]*phi[i];
					break;
				}
				else phi[f[j]*i]=(f[j]-1)*phi[i];
			}
			else break;
		}

		ans+=phi[i];
	}

	cout << ans*2+3 << endl;
	return 0;
}
