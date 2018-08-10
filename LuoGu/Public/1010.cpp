#include <iostream>
using namespace std;

typedef unsigned short ushort;
ushort n;

void dfs(ushort x)
{
	ushort i=15;
	bool f=false;
	
	for (; ; --i)
	{
		if (x&(ushort(1u)<<i))
		{
			if (f) cout << '+';
			f=true;
			cout << '2';
			
			if (i!=1)
			{
				cout << '(';
				if (i==0) cout << '0';
				else if (i==2) cout << '2';
				else dfs(i);
				cout << ')';
			}
		}
		
		if (!i) break;
	}
}

int main()
{
	cin >> n;
	dfs(n);
	cout << endl;
	return 0;
}
