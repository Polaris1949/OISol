#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string s;
int a[3][3];

bool win(int x, bool w)
{
	int i, n=(x-1)/3, m=(x-1)%3;
	a[n][m]=w;
	
	for (i=0; i<3; ++i)
		if (a[i][m]!=w) break;
	
	if (i>=3) return true;
	
	for (i=0; i<3; ++i)
		if (a[n][i]!=w) break;
	
	if (i>=3) return true;
	
	if (n==m)
	{
		for (i=0; i<3; ++i)
			if (a[i][i]!=w) break;
		
		if (i>=3) return true;
	}
	
	if (n+m==2)
	{
		for (i=0; i<3; ++i)
			if (a[i][2-i]!=w) break;
		
		if (i>=3) return true;
	}
	
	return false;
}

int main()
{
	int i;
	cin >> s;
	memset(a, -1, sizeof(a));
	
	for (i=0; i<s.length(); ++i)
		if (win(s[i]-'0', i&1))
		{
			cout << (i&1?"uim wins.":"xiaoa wins.") << endl;
			return 0;
		}
	
	cout << "drew." << endl;
	return 0;
}
