#include <iostream>
using namespace std;

char c[6][8]=
{
	"  +---+",
	" /   /|",
	"+---+ |",
	"|   | +",
	"|   |/",
	"+---+"
}, s[500][500];
int m, n, sm, sn, a[50][50], cb[]={2,1,0,0,0,0}, ce[]={6,6,6,6,5,4};

void paint(int x, int y)
{
	int i, j;

	for (i=5; i>=0; --i)
		for (j=cb[i]; j<=ce[i]; ++j)
		{
			s[x+5-i][y+j]=c[i][j];
			sm=max(sm, x+5-i);
			sn=max(sn, y+j);
		}
}

int main()
{
	int i, j, k;
	cin >> m >> n;

	for (i=0; i<m; ++i)
		for (j=0; j<n; ++j)
			cin >> a[i][j];

	for (i=0; i<m; ++i)
		for (j=0; j<n; ++j)
			for (k=0; k<a[i][j]; ++k)
				paint((m-i-1)*2+k*3, (m-i-1)*2+j*4);

	for (i=sm; i>=0; --i)
	{
		for (j=0; j<=sn; ++j)
			cout << (s[i][j]?s[i][j]:'.');

		cout << '\n';
	}

	return 0;
}
