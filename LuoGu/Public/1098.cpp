#include <iostream>
#include <string>
using namespace std;

int main() {
	int p1, p2, p3;
	string s, ss;
	cin >> p1 >> p2 >> p3 >> s;
	int i=0, j, k;
	
	while (i<s.length()) {
		while (s[i]!='-' && i<s.length()) i++;
		if (i>=s.length()) break;
		
		if (((isalpha(s[i-1])&&isalpha(s[i+1]))||\
		(isdigit(s[i-1])&&isdigit(s[i+1])))&&(s[i-1]<s[i+1])) {
			ss.clear();
			j=(p3==1)?(s[i-1]+1):(s[i+1]-1);
			
			while ((p3==1)?(j<s[i+1]):(j>s[i-1])) {
				for (k=1; k<=p2; k++)
					if (p1==1)
						ss+=tolower(j);
					else if (p1==2)
						ss+=toupper(j);
					else if (p1==3)
						ss+='*';
				
				if (p3==1) j++;
				else if (p3==2) j--;
			}
			
			s.replace(i, 1, ss);
		}
		else i++;
	}
	
	cout << s << endl;
	return 0;
}
