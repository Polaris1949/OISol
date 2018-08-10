#include <iostream>
using namespace std;

int n, k;

int dfs(int i, int j)
{
	if (i==0 || i<j) return 0;
	if (j==1) return 1;
	return dfs(i-j, j)+dfs(i-1, j-1);
}

int main()
{
	cin >> n >> k;
	cout << dfs(n, k) << endl;
	return 0;
}
