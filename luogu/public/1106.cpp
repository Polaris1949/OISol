#include <iostream>
#include <string>
using namespace std;

string n;
int k;

int main()
{
	int i, j, len;
	cin >> n >> k;
	
	i=0;
	len=n.length();
	
	while (i<k)
	{
		j=0;
		
		while (j<len)
		{
			if (n[j]>n[j+1])
			{
				n.replace(j, 1, "");
				break;
			}
			
			++j;
		}
		
		++i;
	}
	
	while (n[0]=='0') n=n.substr(1);
	
	cout << n << endl;
	return 0;
}
