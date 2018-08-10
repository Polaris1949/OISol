#include <iostream>
using namespace std;

int n, f[20];

int main()
{
	int i, j;
	cin >> n;
	f[0]=1; f[1]=1;
	
	for (i=2; i<=n; ++i)
		for (j=0; j<i; ++j)
			f[i]+=f[j]*f[i-j-1];
	
	cout << f[n] << endl;
	return 0;
}
