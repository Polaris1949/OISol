#include <cmath>
#include <iostream>
using namespace std;

int n;

int main()
{
	int i, m, s=0, x=0, y=0;
	cin >> n;

	for (i=0; i<n; i++)
	{
		cin >> m;

		if (m)
		{
			if (y>0) x-=pow(2, y-1);
			if (x<0) x=0;
			x++;
			y=0;

			if (x>=1 && x<3) s+=1;
			if (x>=3 && x<7) s+=2;
			if (x>=7 && x<30) s+=3;
			if (x>=30 && x<120) s+=4;
			if (x>=120 && x<365) s+=5;
			if (x>=365) s+=6;
		}
		else y++;
	}

	cout << s << endl;
	return 0;
}
