#include <algorithm>
#include <iostream>
using namespace std;

struct tree
{
	int l, r, c;
};

int n, a[40005], b[40005], h[40005], x[80005];
tree t[320005];

void build(int p, int l, int r)
{
	t[p].l=l; t[p].r=r;
	
	if (l+1==r) t[p].c=0;
	else
	{
		build(p*2, l, (l+r)>>1);
		build(p*2+1, (l+r)>>1, r);
	}
}

void update(int p, int l, int r, int v)
{
	if (t[p].l>=t[p].r) return;
	if (t[p].l>=l && t[p].r<=r)
	{
		t[p].c=max(t[p].c, v);
		return;
	}
	
	int mid=(t[p].l+t[p].r)>>1;
	
	if (r<=mid) update(p*2, l, r, v);
	else if (l>=mid) update(p*2+1, l, r, v);
	else
	{
		update(p*2, l, mid, v);
		update(p*2+1, mid, r, v);
	}
}

int bfind(int v)
{
	int l=1, r=n<<1, mid;
	
	while (l<=r)
	{
		mid=(l+r)>>1;
		
		if (x[mid]==v) return mid;
		else if (x[mid]<v) l=mid+1;
		else r=mid-1;
	}
}

long long answer(int p, int l, int r)
{
	if (t[p].l+1==t[p].r) return (long long)t[p].c*(x[t[p].r]-x[t[p].l]);
	t[p*2].c=max(t[p*2].c, t[p].c);
	t[p*2+1].c=max(t[p*2+1].c, t[p].c);
	
	int mid=(t[p].l+t[p].r)>>1;
	
	if (r<=mid) return answer(p*2, l, r);
	else if (l>=mid) return answer(p*2+1, l, r);
	else return answer(p*2, l, mid)+answer(p*2+1, mid, r);
}

int main()
{
	int i;
	cin >> n;
	build(1, 1, n<<1);
	
	for (i=1; i<=n; i++)
	{
		cin >> a[i] >> b[i] >> h[i];
		x[(i<<1)-1]=a[i];
		x[i<<1]=b[i];
	}
	
	sort(x+1, x+(n<<1)+1);
	
	for (i=1; i<=n; i++)
	{
		a[i]=bfind(a[i]);
		b[i]=bfind(b[i]);
	}
	
	for (i=1; i<=n; i++)
		update(1, a[i], b[i], h[i]);
	
	cout << answer(1, 1, n<<1) << endl;
	return 0;
}
