#include <iostream>
#include <string>
using namespace std;

string x, y, z;
char f[91];
bool a[91];

int main() {
	cin >> x >> y >> z;
	int i, j;
	
	for (i=0; i<x.length(); i++)
		if (a[x[i]]) {
			if (f[x[i]]!=y[i]) {
				cout << "Failed" << endl;
				return 0;
			}
		}
		else {
			f[x[i]]=y[i];
			a[x[i]]=true;
		}
	
	for (i=65; i<=90; i++)
		for (j=65; j<=90; j++)
			if (f[i]==f[j] && i!=j) {
				cout << "Failed" << endl;
				return 0;
			}
	
	for (i=65; i<=90; i++)
		if (!a[i]) {
			cout << "Failed" << endl;
			return 0;
		}
	
	for (i=0; i<z.length(); i++)
		z[i]=f[z[i]];
	
	cout << z << endl;
	return 0;
}
