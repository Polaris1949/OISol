#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string word[20]=
{
	"one", "two", "three", "four",
	"five", "six", "seven", "eight",
	"nine", "ten", "eleven", "twelve",
	"thirteen", "fourteen", "fifteen", "sixteen",
	"seventeen", "eighteen", "nineteen", "twenty"
};

string n[6];

bool comp(const string& x, const string& y)
{
	return x+y<y+x;
}

int main()
{
	int i, j, x, c=0;
	string s;
	
	for (i=0; i<6; i++)
	{
		cin >> s;
		x=0;
		
		for (j=0; j<20; j++)
		{
			if (s==word[j])
			{
				x=j+1;
				break;
			}
		}
		
		if (!x)
		{
			if (s=="a" || s=="another" || s=="first") x=1;
			else if (s=="both" || s=="second") x=2;
			else if (s=="third") x=3;
			else continue;
		}
		
		x=x*x%100;
		
		if (x<10) n[c++]=string(1, '0')+string(1, x%10+'0');
		else n[c++]=string(1, x/10+'0')+string(1, x%10+'0');
	}
	
	sort(n, n+6, comp);
	s="";
	
	for (i=0; i<c; i++)
	{
		s+=n[i];
	}
	
	while (s.length()>1)
	{
		if (s[0]=='0') s.erase(s.begin());
		else break;
	}
	
	if (s=="") cout << "0" << endl;
	else cout << s << endl;
	
	return 0;
}
