#include <algorithm>
#include <iostream>
using namespace std;

int n, a[40001], c[40001], num[40001];

int lowbit(int x)
{
	return (x&(-x));
}

bool comp(int x, int y)
{
	return a[x]<a[y];
}

int main()
{
	int i, j, s=0;
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> a[i];
		num[i]=i;
	}
	
	sort(num, num+n, comp);
	
	for (i=0; i<n; i++)
		a[num[i]]=i;
	
	for (i=0; i<n; i++)
	{
		for (j=n-a[i]; j>=1; j-=lowbit(j))
			s+=c[j];
		
		for (j=n-a[i]; j<=n; j+=lowbit(j))
			c[j]++;
	}
	
	cout << s << endl;
	return 0;
}
