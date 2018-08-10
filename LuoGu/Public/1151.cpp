#include <iostream>
using namespace std;

int k;

int main()
{
	int i, s1, s2, s3;
	bool f=false;
	cin >> k;
	
	for (i=10000; i<=30000; i++)
	{
		s1=i/100;
		s2=i/10%1000;
		s3=i%1000;
		
		if (s1%k==0 && s2%k==0 && s3%k==0)
		{
			f=true;
			cout << i << endl;
		}
	}
	
	if (!f) cout << "No" << endl;
	return 0;
}
