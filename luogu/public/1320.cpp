#include <iostream>
#include <stack>
#include <string>
using namespace std;

string x, y;
stack<bool> s;

int main()
{
	bool f=false;
	int size=0;
	
	while (cin >> y)
	{
		x+=y;
		++size;
	}
	
	cout << size;
	x+='\0';
	
	for (char c : x)
	{
		s.push(c-'0');
		
		if (f^(c-'0'))
		{
			s.pop();
			cout << ' ' << s.size();
			while (!s.empty()) s.pop();
			s.push(c-'0');
			f=!f;
		}
	}
	
	cout << '\n';
	return 0;
}
