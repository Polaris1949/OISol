#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

typedef pair<int, int> pii;

const int maxn = 1 << 17;
int n, q;
pii mat[maxn];
int delta[2 * maxn];
int dist[2 * maxn];

int qa, qb;
int getd(int a, int b) {
	return abs(mat[a].first - mat[b].first) + abs(mat[a].second - mat[b].second);
}

void build(int rt, int a, int b) {
	if (a > b) return;
	if (a == b) {
		if (a < n - 1) delta[rt] = getd(a, a + 1) + getd(a + 1, a + 2) - getd(a, a + 2);
		else delta[rt] = 0;
		if (a < n) dist[rt] = getd(a, a + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	build(rt * 2, a, mid);
	build(rt * 2 + 1, mid + 1, b);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

int query_dist(int rt, int a, int b) {
	if (a > qb || b < qa) return 0;
	if (qa <= a && b <= qb) return dist[rt];
	int mid = (a + b) / 2;
	return query_dist(rt * 2, a, mid) + query_dist(rt * 2 + 1, mid + 1, b);
}

int query_delta(int rt, int a, int b) {
	if (a > qb || b < qa) return 0;
	if (qa <= a && b <= qb) return delta[rt];
	int mid = (a + b) / 2;
	return max(query_delta(rt * 2, a, mid), query_delta(rt * 2 + 1, mid + 1, b));
}

void update_dist(int rt, int a, int b) {
	if (a > qb || b < qa) return;
	if (qa <= a && b <= qb) {
		if (a >= 1 && a < n) dist[rt] = getd(a, a + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	update_dist(rt * 2, a, mid);
	update_dist(rt * 2 + 1, mid + 1, b);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

void update_delta(int rt, int a, int b) {
	if (a > qb || b < qa) return;
	if (qa <= a && b <= qb) {
		if (a >= 1 && a < n - 1) delta[rt] = getd(a, a + 1) + getd(a + 1, a + 2) - getd(a, a + 2);
		else delta[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	update_delta(rt * 2, a, mid);
	update_delta(rt * 2 + 1, mid + 1, b);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
}

int main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &mat[i].first, &mat[i].second);
	}
	build(1, 1, n);
	for (int i = 0; i < q; i++) {
		char c[2];
		scanf("%s", c);
		if (c[0] == 'Q') {
			scanf("%d%d", &qa, &qb);
			qb--;
			int tot = query_dist(1, 1, n);
			qb--;
			int del = query_delta(1, 1, n);
			printf("%d\n", tot - del);
		}
		else {
			int ix, pa, pb;
			scanf("%d%d%d", &ix, &pa, &pb);
			mat[ix].first = pa;
			mat[ix].second = pb;
			for (int j = ix - 1; j <= ix; j++) {
				qa = j; qb = j;
				update_dist(1, 1, n);
			}
			for (int j = ix - 2; j <= ix; j++) {
				qa = j; qb = j;
				update_delta(1, 1, n);
			}
		}
	}
}
