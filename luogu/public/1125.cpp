#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int a[128], maxv, minv, q;
string s;

bool prime(int x) {
	if (x<2) return false;
	
	int k;
	
	for (k=2; k<=sqrt(x); k++)
		if (x%k==0) return false;
	
	return true;
}

int main() {
	int i, l;
	
	cin >> s;
	l=s.size();
	
	for (i=0; i<l; i++)
		a[s[i]]++;
	
	maxv=a[32];
	minv=100;
	
	for (i=33; i<128; i++) {
		if (a[i]>maxv) maxv=a[i];
		if (a[i]<minv && a[i]!=0) minv=a[i];
	}
	
	q=maxv-minv;
	
	if (prime(q)) cout << "Lucky Word" << endl << q << endl;
	else cout << "No Answer" << endl << 0 << endl;
	
	return 0;
}
