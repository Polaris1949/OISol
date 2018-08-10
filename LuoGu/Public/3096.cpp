#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxk = 205;
const int maxn = 21005;
const int maxm = 21005;
const ll inf = 1ll<<55;

int n, m, k, q, cnt, tot;
int hub[maxk], is[maxn], V[maxm], N[maxm], F[maxn];
ll C[maxm], e[maxk][maxk], d[maxk][maxn];

void add(int a,int b,ll c)
{
	V[++tot] = b, C[tot] = c, N[tot] = F[a], F[a] = tot;
}

void dw(ll &x, ll y)
{
	if (y < x) x = y;
}

int main()
{
	char ch;
	int a,b,c,i,j,z;
	ll v;
#define read(x) \
	{\
		ch = getchar(), x = 0;\
		while (ch < '0' || ch > '9') ch = getchar();\
		while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();\
	}
	tot = 0;
	memset(N,0,sizeof(N));
	memset(F,0,sizeof(F));

	read(n);
	read(m);
	read(k);
	read(q);
	for (i = 0; i < m; i ++)
	{
		read(a);
		read(b);
		read(v);
		-- a, -- b, add(a,b,v);
	}
	memset(is,-1,sizeof(is));
	for (i = 0; i < k; i ++)
	{
		read(hub[i]);
		is[--hub[i]] = i;
	}

	for (i = 0; i < k; i ++)
		for (j = 0; j < k; j ++) e[i][j] = inf;
	for (i = 0; i < k; i ++)
	{
		a = hub[i];
		for (int p1 = F[a]; p1 > 0; p1 = N[p1])
		{
			if (is[b = V[p1]] >= 0)
			{
				dw(e[i][is[b]], C[p1]);
				continue;
			}
			for (int p2 = F[b]; p2 > 0; p2 = N[p2])
				if (is[c = V[p2]] >= 0 && i != is[c]) dw(e[i][is[c]], C[p1] + C[p2]);
		}
	}

	for (i = 0; i < k; i ++) e[i][i] = 0;
	for (z = 0; z < k; z ++)
		for (i = 0; i < k; i ++)
			for (j = 0; j < k; j ++)
				if (i != j && i != z && j != z) dw(e[i][j], e[i][z] + e[z][j]);

	for (i = 0; i < k; i ++)
		for (j = 0; j < n; j ++) d[i][j] = inf;
	for (i = 0; i < k; i ++)
		for (j = 0; j < k; j ++) d[i][hub[j]] = e[i][j];

	for (i = 0; i < k; i ++)
	{
		for (int p = F[a = hub[i]]; p > 0; p = N[p])
			for (j = 0; j < k; j ++)
			{
				dw(d[j][b = V[p]], e[j][i] + C[p]);
			}
	}

	ll tmp, res = 0;
	cnt = 0;
	while (q --)
	{
		read(a);
		read(b);
		-- a, -- b;
		if (is[a] >= 0) tmp = d[is[a]][b];
		else
		{
			tmp = inf;
			for (int p = F[a]; p > 0; p = N[p])
				if (is[c = V[p]] >= 0) dw(tmp, C[p] + d[is[c]][b]);
		}
		if (tmp < inf) cnt ++, res += tmp;
	}
	printf("%d\n",cnt);
	printf("%lld\n",res);
	return 0;
}
