#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string s;
int a[3]= {0};

int main()
{
	string s;
	cin >> s;

	for (int i=0; i<s.length()-1; ++i)
	{
		if (s[i]=='=')
			if (isdigit(s[i+1]))
				a[s[i-2]-'a']=s[i+1]-'0';
			else
				a[s[i-2]-'a']=a[s[i+1]-'a'];
	}

	cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	return 0;
}
