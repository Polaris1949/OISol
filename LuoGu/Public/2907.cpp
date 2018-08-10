#include <iostream>
using namespace std;

int n, k, ans;

void dfs(int x)
{
	if (x<=k || (x-k)%2)
	{
		++ans;
		return;
	}

	dfs((x-k)/2);
	dfs((x+k)/2);
}

int main()
{
	cin >> n >> k;
	dfs(n);
	cout << ans << endl;
	return 0;
}
