#include <cstring>
#include <iostream>
using namespace std;

const int pow2[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int n;
char a[1024][2048];

void print(int x, int y)
{
	a[x][y]='/';
	a[x][y+1]='\\';
	a[x+1][y-1]='/';
	a[x+1][y+2]='\\';
	a[x+1][y]='_';
	a[x+1][y+1]='_';
}

void solve(int x, int y, int k)
{
	if (k==1)
	{
		print(x, y);
		return;
	}
	
	solve(x, y, k-1);
	solve(x+pow2[k-1], y-pow2[k-1], k-1);
	solve(x+pow2[k-1], y+pow2[k-1], k-1);
}

int main()
{
	int i, j;
	cin >> n;
	
	memset(a, ' ', sizeof(a));
	solve(0, pow2[n]-1, n);
	
	for (i=0; i<pow2[n]; i++)
	{
		for (j=0; j<pow2[n+1]; j++)
			cout << a[i][j];
		
		cout << endl;
	}
	
	return 0;
}
