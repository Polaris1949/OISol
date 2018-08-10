#include <iostream>
using namespace std;

int n, x;

int main()
{
	int i, s0=0, s5=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> x;
		if (x==0) s0++;
		if (x==5) s5++;
	}
	
	if (s0<=0 && s5<=9) cout << -1;
	else if (s0>0 && s5<9) cout << 0;
	else
	{
		for (i=0; i<s5/9*9; i++) cout << 5;
		for (i=0; i<s0; i++) cout << 0;
	}
	
	cout << endl;
	return 0;
}
