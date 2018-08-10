#include <iostream>
using namespace std;

int n, a[100];

int main()
{
	int i, j, s;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> a[i];
		s=0;
		
		for (j=0; j<i; j++)
			if (a[j]<a[i]) s++;
		
		cout << s << ' ';
	}
	
	cout << endl;
	return 0;
}
