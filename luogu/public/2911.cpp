#include <iostream>
using namespace std;

int s1, s2, s3, s[81];

int main()
{
	int i, j, k, x, c=0, ans=0;
	cin >> s1 >> s2 >> s3;
	
	for (i=1; i<=s1; i++)
		for (j=1; j<=s2; j++)
			for (k=1; k<=s3; k++)
			{
				x=++s[i+j+k];
				
				if (x>c || (x==c && i+j+k<ans))
				{
					c=s[i+j+k];
					ans=i+j+k;
				}
			}
	
	cout << ans << endl;
	return 0;
}
