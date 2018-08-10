#include <iostream>
#include <string>
using namespace std;

string s1, s2;

void dfs(int xb, int xe, int yb, int ye)
{
	int m=s1.find(s2[ye]);
	cout << s2[ye];
	if (m>xb) dfs(xb, m-1, yb, yb+m-xb-1);
	if (m<xe) dfs(m+1, xe, yb+m-xb, ye-1);
}

int main()
{
	cin >> s1 >> s2;
	dfs(0, s1.length()-1, 0, s2.length()-1);
	cout << endl;
	return 0;
}
