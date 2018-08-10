#include <iostream>
using namespace std;

int d[7], m[12]= {31,0,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int n, i, j, c, w=0;
	cin >> n;

	for (i=1900; i<1900+n; i++)
	{
		if ((i%4==0 && i%100!=0) || i%400==0) m[1]=29;
		else m[1]=28;

		for (j=0; j<12; j++)
			for (c=1; c<=m[j]; c++)
			{
				if (c==13) d[w]++;
				w++;
				if (w>=7) w=0;
			}
	}

	for (i=5; i<12; i++)
	{
		if (i!=5) cout << ' ';
		cout << d[i%7];
	}

	cout << endl;
	return 0;
}
