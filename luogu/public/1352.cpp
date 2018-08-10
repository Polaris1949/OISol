#include <iostream>
#include <vector>
using namespace std;

int n, a[6001], s[6001][2];
vector<int> ch[6001];

void calc(int p)
{
	int i;
	
	for (i=0; i<ch[p].size(); i++)
	{
		calc(ch[p][i]);
		s[p][0]+=max(s[ch[p][i]][0], s[ch[p][i]][1]);
		s[p][1]+=s[ch[p][i]][0];
	}
	
	s[p][1]+=a[p];
}

int main()
{
	int i, l, k, root=0;
	cin >> n;
	
	for (i=1; i<=n; i++)
		cin >> a[i];
	
	for (i=1; i<=n-1; i++)
	{
		cin >> l >> k;
		ch[k].push_back(l);
		root+=l;
	}
	
	root=n*(n+1)/2-root;
	calc(root);
	
	cout << max(s[root][0], s[root][1]) << endl;
	return 0;
}
