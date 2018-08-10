#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string w, s, ss;

int main() {
	int i, j, k, c=0;
	getline(cin, w);
	getline(cin, s);
	
	for (i=0; i<w.length(); i++)
		w[i]=tolower(w[i]);
	
	for (i=0; i<s.length(); i++)
		s[i]=tolower(s[i]);
	
	i=0;
	
	while (i<s.length()) {
		while (s[i]==' ' && i<s.length()) i++;
		j=i;
		
		while (s[i]!=' ' && i<s.length()) i++;
		
		ss=s.substr(j, i-j);
		
		if (ss==w) {
			c++;
			if (c==1) k=j;
		}
	}
	
	if (c>0) cout << c << ' ' << k << endl;
	else cout << -1 << endl;
	
	return 0;
}
