#include <iostream>
#include <string>
using namespace std;

int n;

void dfs(string t, int d)
{
	if (d==0)
	{
		switch (t[0])
		{
			case '0': cout << 'B'; break;
			case '1': cout << 'I'; break;
		}
		
		return;
	}
	
	int len=t.length()/2;
	dfs(t.substr(0, len), d-1);
	dfs(t.substr(len, len), d-1);
	
	bool f=true;
	
	for (int i=0; i<len*2; i++)
		if (t[i]!=t[0])
		{
			f=false;
			break;
		}
	
	if (!f) cout << 'F';
	else if (t[0]=='0') cout << 'B';
	else cout << 'I';
}

int main()
{
	string t;
	cin >> n >> t;
	dfs(t, n);
	cout << endl;
	return 0;
}
