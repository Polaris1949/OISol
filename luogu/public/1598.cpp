#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string s;
struct node {
	char c;
	int n;
} a[26];

bool comp(node x, node y) {
	if (x.n!=y.n) return x.n>y.n;
	else return x.c<y.c;
}

int main() {
	int i, j, k, p;
	
	for (i=0; i<26; i++) a[i].c=i+'A';
	
	for (i=0; i<4; i++) {
		getline(cin, s);
		
		for (j=0; j<s.length(); j++) {
			if (isupper(s[j])) a[s[j]-'A'].n++;
		}
	}
	
	while (true) {
		sort(a, a+26, comp);
		if (a[0].n==0) break;
		i=0; k=a[i].n; p='A';
		if (a[0].c!=p) cout << ' ';
		
		while (a[i].n==k) {
			for (j=p+1; j<a[i].c; j++) cout << ' ';
			for (j=p; j<a[i].c; j++) cout << ' ';
			cout << '*';
			a[i].n--; p=j; i++;
		}
		
		cout << endl;
	}
	
	for (i=0; i<26; i++)
		if (i==0) cout << a[i].c;
		else cout << ' ' << a[i].c;
	
	cout << endl;
	return 0;
}
