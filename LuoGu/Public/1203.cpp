#include<iostream>
#include<cmath>
using namespace std;

int i,n,xl[1111]={0},ans=0;;
char c;

int NecklaceR(int k)
{
	int j=k,maxR=0,maxB=0;
	while (xl[j++]!=2) maxB++;
	j=k;
	while (xl[j++]!=1) maxR++;
	return max(maxR,maxB);
}

int NecklaceL(int k)
{
	int j=k,maxR=0,maxB=0;
	while (xl[j--]!=2) maxB++;
	j=k;
	while (xl[j--]!=1) maxR++;
	return max(maxR,maxB);
}

int main()
{
	cin>>n;
	
	for (i=1; i<=n; i++)
	{
		cin>>c;
		if (c=='b') xl[i]=1;
		if (c=='r') xl[i]=2;
		xl[i+n]=xl[i];
	}
	
	for (i=1; i<=n; i++)
	{
		ans=max(NecklaceR(i+1)+NecklaceL(i+n),ans);
		
		if (ans>=n)
		{
			ans=n;
			break;
		}
	}
	
	cout << ans << endl;
	return 0;
}
