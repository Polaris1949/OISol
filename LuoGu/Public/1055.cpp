#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int i, j=1, len=str.length(), s=0;
	
	for (i=0; i<12; i++) {
		while (str[i]!='-') {
			s+=(str[i]-'0')*j;
			i++; j++;
		}
	}
	
	s%=11;
	if (str[i]-'0'==s || (str[i]=='X' && s==10))
		cout << "Right" << endl;
	else {
		if (s!=10) str[i]=s+'0';
		else str[i]='X';
		cout << str << endl;
	}
	
	return 0;
}
