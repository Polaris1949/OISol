#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void answer(bool out, int v)
{
	if (out) printf("Yes\n");
	else printf("No\n");
	printf("%d\n", v);
	return;
}

int d[14][300001];

int main()
{
	int m, s, t;
	scanf("%d%d%d", &m, &s, &t);
	int ti=0, dist=0;

	while (m>=10)
	{
		m-=10;
		dist+=60;

		if (dist>=s)
		{
			answer(true, ti+1);
			return 0;
		}
		if ((++ti)==t)
		{
			answer(false, dist);
			return 0;
		}
	}

	memset(d, 0, sizeof(d));
	int i, j;

	for (j=0; j<=13; j++)
		d[j][ti]=-(1<<30);

	d[m][ti]=dist;

	for (i=ti; i<t; i++)
	{
		for (j=0; j<=13; j++)
			d[j][i+1]=-(1<<30);

		for (j=0; j<=13; j++)
		{
			if (d[j][i]>=s)
			{
				answer(true, i);
				return 0;
			}

			d[j][i+1]=max(d[j][i]+17, d[j][i+1]);
			if (j>=4) d[j][i+1]=max(d[j-4][i], d[j][i+1]);
			if (j<4) d[j][i+1]=max(d[j+10][i]+60, d[j][i+1]);
		}
	}

	int maxv=0;
	for (j=0; j<=13; j++)
		if (d[j][t]>=maxv)
		{
			maxv=d[j][t];
			if (maxv>=s)
			{
				answer(true, i);
				return 0;
			}
		}

	answer(false, maxv);
	return 0;
}
