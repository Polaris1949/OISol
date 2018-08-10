#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef unsigned int uint;
const uint INF=1000000;
const uint MOD=9987;

uint n, e;
vector<vector<uint>> g;
queue<uint> q;
vector<bool> inq;
vector<uint> dist;

void spfa(uint s)
{
	uint i, x;

	for (i=0; i<n; ++i)
		dist[i]=INF;

	q.push(s);
	inq[s]=true;
	dist[s]=1;

	while (!q.empty())
	{
		x=q.front();
		q.pop();
		inq[x]=false;

		for (i=0; i<n; ++i)
		{
			if (g[x][i]>0 && dist[x]*g[x][i]<dist[i])
			{
				dist[i]=dist[x]*g[x][i];

				if (!inq[i])
				{
					q.push(i);
					inq[i]=true;
				}
			}
		}
	}
}

int main()
{
	uint i, x, y, w;
	cin >> n >> e;
	g.resize(n, vector<uint>(n));
	inq.resize(n);
	dist.resize(n);

	for (i=0; i<e; ++i)
	{
		cin >> x >> y >> w;
		g[--x][--y]=w;
	}

	spfa(0);
	cout << dist[n-1]%MOD << endl;
	return 0;
}
