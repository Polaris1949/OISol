#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, ans[1250][2], temp[1250][2];

void prime(int x)
{
	memset(temp, 0, sizeof(temp));
	
	int i=2, &s=temp[1249][0];
	
	while (x!=1)
	{
		if (x%i==0)
		{
			temp[s][0]=i;
			
			while (x%i==0)
			{
				temp[s][1]++;
				x/=i;
			}
			
			s++;
		}
		
		i++;
	}
}

void merge()
{
	int i, j=0, ts=temp[1249][0], &s=ans[1249][0];
	
	for (i=0; i<ts; i++, j++)
	{
		if (ans[j][0])
		{
			if (ans[j][0]==temp[i][0])
				ans[j][1]+=temp[i][1];
			else if (ans[j][0]<temp[i][0])
			{
				while (j<s && ans[j][0] && ans[j][0]<temp[i][0]) j++;
				
				if (ans[j][0]==0)
				{
					ans[j][0]=temp[i][0];
					ans[j][1]=temp[i][1];
				}
				else if (ans[j][0]==temp[i][0])
					ans[j][1]+=temp[i][1];
			}
		}
		else
		{
			ans[j][0]=temp[i][0];
			ans[j][1]=temp[i][1];
		}
	}
	
	if (j>s) s=j;
}

int main()
{
	int i;
	cin >> n;
	
	for (i=2; i<=n; i++)
	{
		prime(i);
		merge();
	}
	
	for (i=0; i<ans[1249][0]; i++)
		cout << ans[i][0] << ' ' << ans[i][1] << endl;
	
	return 0;
}
