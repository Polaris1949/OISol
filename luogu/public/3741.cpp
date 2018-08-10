#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main()
{
	size_t i, ans=0;
	cin >> n >> s;
	
	while (!s.empty())
	{
		i=s.find("VK");
		
		if (i==string::npos)
		{
			for (i=0; i<s.length()-1; i++)
				if ((s[i]=='V' && s[i+1]=='V')
					|| (s[i]=='K' && s[i+1]=='K'))
				{
					ans++; break;
				}
			
			break;
		}
		else
			s.replace(i, 2, "__");
		
		ans++;
	}
	
	cout << ans << endl;
	return 0;
}
