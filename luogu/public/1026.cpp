#include <iostream>
#include <string>
#include <vector>
using namespace std;

int p, k, s;
int m[200][200], f[200][40];
vector<string> g[26];

bool ok(string ss)
{
	if (g[ss.front()-'a'].empty())
		return false;
	else
		for (const string& x : g[ss.front()-'a'])
			if (ss.length()>=x.length() && ss.substr(0, x.length())==x)
				return true;

	return false;
}

int main()
{
	int i, j, o, len;
	string w, x;
	cin >> p >> k;
	len=p*20;

	for (i=0; i<p; i++)
	{
		cin >> x;
		w+=x;
	}

	cin >> s;

	for (i=0; i<s; i++)
	{
		cin >> x;
		g[x.front()-'a'].push_back(x);
	}

	for (j=len-1; j>=0; j--)
		for (i=j; i>=0; i--)
			m[i][j]=m[i+1][j]+ok(w.substr(i, j-i+1));

	f[0][0]=m[0][0];

	for (i=1; i<k; i++)
		f[i][i]=f[i-1][i-1]+m[i][i];

	for (i=0; i<len; i++)
		f[i][0]=m[0][i];

	for (i=0; i<len; i++)
		for (j=1; j<k && j<i; j++)
			for (o=j; o<i; o++)
				if (f[o][j-1]+m[o+1][i]>f[i][j])
					f[i][j]=f[o][j-1]+m[o+1][i];

	cout << f[len-1][k-1] << endl;
	return 0;
}
