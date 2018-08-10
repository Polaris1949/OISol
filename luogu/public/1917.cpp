#include <iostream>
using namespace std;

int main()
{
	char o;
	int i, j, ans=0;
	bool f=false;

	for (i=0; i<3; ++i)
		for (j=0; j<3; ++j)
		{
			cin >> o;

			if (o!='-')
			{
				++ans;
				if (o=='X' && abs(i-j)==1) f=true;
			}
		}

	if (f) cout << "xiaoa will win." << endl;
	else cout << "Dont know." << endl;
	cout << ans << endl;
	return 0;
}
