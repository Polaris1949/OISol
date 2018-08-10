#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	int i, b=0, g=0;
	cin >> s;

	for (i=0; i<s.size()-2; ++i)
	{
		if (s[i]=='b' || s[i+1]=='o' || s[i+2]=='y') ++b;
		if (s[i]=='g' || s[i+1]=='i' || s[i+2]=='r' || s[i+3]=='l') ++g;
	}

	cout << b << endl << g << endl;
	return 0;
}
