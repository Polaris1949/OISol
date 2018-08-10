#include <iostream>
using namespace std;

int n, root[31][31];
long long f[31][31];

long long search(int l, int r)
{
	if (l>r) return 1;
	
	int k;
	long long ans;
	
	if (f[l][r]==-1)
		for (k=l; k<=r; k++)
		{
			ans=search(l, k-1)*search(k+1, r)+f[k][k];
			
			if (ans>f[l][r])
			{
				f[l][r]=ans;
				root[l][r]=k;
			}
		}
	
	return f[l][r];
}

void preorder(int l, int r)
{
	if (l>r) return;
	
	cout << root[l][r] << ' ';
	preorder(l, root[l][r]-1);
	preorder(root[l][r]+1, r);
}

int main()
{
	int i, j;
	cin >> n;
	
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			f[i][j]=-1;
	
	for (i=1; i<=n; i++)
	{
		cin >> f[i][i];
		root[i][i]=i;
	}
	
	cout << search(1, n) << endl;
	preorder(1, n);
	cout << endl;
	
	return 0;
}
