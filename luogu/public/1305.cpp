#include <iostream>
using namespace std;

struct node
{
	char lc, rc;
};

node tree[1000];

void preorder(char c)
{
	cout << c;
	if (tree[c].lc!='*') preorder(tree[c].lc);
	if (tree[c].rc!='*') preorder(tree[c].rc);
}

int main()
{
	int n, i;
	char c, b;
	cin >> n;

	for (i=1; i<=n; i++)
	{
		cin >> c;
		if (i==1) b=c;
		cin >> tree[c].lc >> tree[c].rc;
	}

	preorder(b);
	cout << endl;
	return 0;
}
