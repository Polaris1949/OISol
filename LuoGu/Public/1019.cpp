#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int n, ans=0, c;
int u[20], l[20][20];
char ch;
string s[20], str;

int overlap(int x, int y)
{
	if (l[x][y]) return l[x][y];
	int i, j, lx=s[x].length(), len=min(s[x].length(), s[y].length());

	for (i=1; i<len; i++)
	{
		for (j=0; j<i; j++)
			if (s[x][lx-i+j]!=s[y][j]) break;

		if (j>=i)
		{
			l[x][y]=i;
			return i;
		}
	}

	return 0;
}

void dfs(int x)
{
	int i, o;

	for (i=0; i<n; i++)
	{
		o=overlap(x, i);

		if (u[i]<2 && o)
		{
			u[i]++;
			c+=s[i].length()-o;
			ans=max(ans, c);
			dfs(i);
			u[i]--;
			c-=s[i].length()-o;
		}
	}
}

int main()
{
	int i;
	cin >> n;

	for (i=0; i<n; i++)
		cin >> s[i];

	cin >> ch;
	str=ch;

	for (i=0; i<n; i++)
		if (s[i][0]==ch)
		{
			memset(u, 0, sizeof(u));
			c=s[i].length();
			ans=max(ans, c);
			u[i]++;
			dfs(i);
		}

	cout << ans << endl;
	return 0;
}
