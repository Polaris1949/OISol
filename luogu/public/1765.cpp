#include <iostream>
#include <string>
using namespace std;

const int c[26]={1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4,
	1, 2, 3, 1, 2, 3, 4};
string s;
int ans;

int main()
{
	getline(cin, s);

	for (char e : s)
	{
		if (e==' ') ++ans;
		else if (islower(e)) ans+=c[e-'a'];
	}

	cout << ans << endl;
	return 0;
}
