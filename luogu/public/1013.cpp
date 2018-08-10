#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node
{
	bool f;
	int first, second;
};

vector<vector<node>> a;
int n;
vector<int> num;
map<char, int> mcn;
map<int, char> mnc;

bool check()
{
	bool ret=true;
	int i, j;

	for (i=0; i<n-1&&ret; ++i)
		for (j=0; j<n-1&&ret; ++j)
		{
			if (a[i][j].f)
			{
				if (num[a[i][j].first]*(n-1)+num[a[i][j].second]
						!=num[i]+num[j])
					ret=false;
			}
			else
			{
				if (num[a[i][j].second]!=num[i]+num[j])
					ret=false;
			}
		}

	return ret;
}

int main()
{
	int i, j, one, cur;
	char c;
	string s;
	cin >> n;
	num.resize(n-1, -1);
	a.resize(n-1, vector<node>(n-1));

	for (i=0; i<n; ++i)
	{
		cin >> c;

		if (i>0)
		{
			mcn[c]=i-1;
			mnc[i-1]=c;
		}
	}

	for (i=1; i<n; ++i)
	{
		cin >> c;

		for (j=1; j<n; ++j)
		{
			cin >> s;

			if (s.size()==1)
			{
				a[mcn[c]][j-1].f=false;
				a[mcn[c]][j-1].first=0;
				a[mcn[c]][j-1].second=mcn[s[0]];
			}
			else
			{
				a[mcn[c]][j-1].f=true;
				a[mcn[c]][j-1].first=mcn[s[0]];
				a[mcn[c]][j-1].second=mcn[s[1]];
				num[mcn[s[0]]]=1;
				one=mcn[s[0]];
			}
		}
	}

	for (i=0; i<n-1; ++i)
		if (!a[one][i].first&&a[one][i].second==one)
			num[i]=0;

	cur=one;

	for (i=2; i<n-1; ++i)
	{
		num[a[one][cur].second]=i;
		cur=a[one][cur].second;
	}

	if (!check())
		cout << "ERROR!" << endl;
	else
	{
		for (i=0; i<n-1; ++i)
			cout << mnc[i] << '=' << num[i] << ' ';

		cout << endl << n-1 << endl;
	}

	return 0;
}
