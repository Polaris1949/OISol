#include <iostream>
#include <string>
using namespace std;

string ip[8];
bool z[8];

int main()
{
	int i, j, maxv=0, s=0, pos=-1;
	char c;
	bool f;

	for (i=0; i<8; ++i)
	{
		if (i) cin >> c;
		f=false;

		for (j=0; j<4; ++j)
		{
			cin >> c;
			if (c!='0') f=true;
			if (f) ip[i]+=c;
		}

		if (ip[i].empty())
		{
			ip[i]='0';
			z[i]=true;
		}
	}

	for (i=0; i<8; ++i)
	{
		if (z[i]) ++s;
		else
		{
			if (s>maxv)
			{
				maxv=s;
				pos=i;
			}

			s=0;
		}
	}

	if (s>maxv)
	{
		maxv=s;
		pos=i;
	}

	f=false;

	for (i=0; i<8; ++i)
	{
		if (i==pos-maxv)
		{
			cout << "::";
			f=true;
		}
		else if (i>pos-maxv&&i<pos);
		else
		{
			if (i&&!f) cout << ':';
			f=false;
			cout << ip[i];
		}
	}

	cout << endl;
	return 0;
}
