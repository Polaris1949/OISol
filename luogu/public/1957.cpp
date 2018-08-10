#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main()
{
	int i, x, y, o, c;
	bool f;
	cin >> n;

	for (i=0; i<n; i++)
	{
		cin >> s;
		f=true;

		switch (s[0])
		{
			case 'a':
				o=0;
				break;
			case 'b':
				o=1;
				break;
			case 'c':
				o=2;
				break;
			default:
				f=false;
				break;
		}

		if (f) cin >> x;
		else x=stoi(s);
		cin >> y;

		switch (o)
		{
			case 0:
				c=x+y;
				break;
			case 1:
				c=x-y;
				break;
			case 2:
				c=x*y;
				break;
		}

		s=to_string(x)+(o==0?'+':(o==1?'-':'*'))
		  +to_string(y)+'='+to_string(c);
		cout << s << endl << s.length() << endl;
	}

	return 0;
}
