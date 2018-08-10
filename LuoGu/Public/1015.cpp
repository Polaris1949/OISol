#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<int> a, b;

bool ok()
{
	b=a;
	reverse(b.begin(), b.end());
	return a==b;
}

int main()
{
	int i, j, x;
	cin >> n >> s;

	for (char c : s)
	{
		if (isdigit(c)) a.push_back(c-'0');
		else a.push_back(islower(c)?c-'a'+10:c-'A'+10);
	}

	if (ok())
	{
		cout << "STEP=0" << endl;
		return 0;
	}

	for (i=0; i<30; ++i)
	{
		x=a.size();

		for (j=0; j<x; ++j)
		{
			a[j]+=b[j];

			if (j!=x-1) a[j+1]+=a[j]/n;
			else if (a[j]>=n) a.push_back(a[j]/n);

			a[j]%=n;
		}

		if (ok())
		{
			cout << "STEP=" << i+1 << endl;
			return 0;
		}
	}

	cout << "Impossible!" << endl;
	return 0;
}
