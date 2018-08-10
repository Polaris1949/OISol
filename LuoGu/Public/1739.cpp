#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	int i, l=0, r=0;
	cin >> s;
	
	for (i=0; i<s.length(); i++)
	{
		if (s[i]=='@') break;
		if (s[i]=='(') l++;
		if (s[i]==')') r++;
	}
	
	cout << (l==r?"YES":"NO") << endl;
	return 0;
}
