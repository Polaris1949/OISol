#include <algorithm>
#include <iostream>
using namespace std;

int h[100], up[100], dn[100];

int main()
{
	int i, pos, c=0, ku=0, kd=0;
	
	while (cin >> h[c++]);
	c--;
	
	for (i=0; i<c; i++)
	{
		if (i==0)
		{
			up[ku++]=dn[kd++]=h[i];
			continue;
		}
		
		pos=lower_bound(up, up+ku, h[i])-up;
		up[pos]=h[i];
		if (pos==ku) ku++;
		pos=lower_bound(dn, dn+kd, h[i], greater_equal<int>())-dn;
		dn[pos]=h[i];
		if(pos==kd) kd++;
	}
	
	cout << kd << endl << ku << endl;
	return 0;
}
