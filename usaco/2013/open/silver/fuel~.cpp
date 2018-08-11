#define NMAX 50000

struct station {
	int pos, cost;
	bool operator<(station const& o) const {
		return pos < o.pos;
	}
};
station stations[NMAX];

int s[NMAX];
int nextSmall[NMAX];

int main() {
#ifndef HOME
	freopen("fuel.in","r",stdin);
	freopen("fuel.out","w",stdout);
#endif

	int n, maxGas, curGas, dist;
	scanf("%d %d %d %d", &n, &maxGas, &curGas, &dist);
	for (int i = 0; i < n; i++) {
		scanf("%d", &stations[i].pos);
		scanf("%d", &stations[i].cost);
	}
	sort(stations, stations + n);

	// find next cheaper station for each station
	int stacklen = 0;
	for (int i = n-1; i >= 0; i--) {
		while (stacklen > 0 && stations[s[stacklen-1]].cost >= stations[i].cost) {
			stacklen--;
		}
		nextSmall[i] = (stacklen == 0 ? -1 : s[stacklen-1]);
		s[stacklen] = i;
		stacklen++;
	}

	curGas -= stations[0].pos;	// move to station 1
	long long cost = 0;
	for (int i = 0; i < n; i++) {
		// gas is less than 0 means it is impossible to reach the station
		if (curGas < 0) {
			printf("-1\n");
			return 0;
		}
		int gasNeeded = min(maxGas, (nextSmall[i] == -1 ? dist :
stations[nextSmall[i]].pos) - stations[i].pos);
		if (gasNeeded > curGas) {
			cost += (long long) (gasNeeded - curGas) * (long long) stations[i].cost;
			curGas = gasNeeded;
		}
		curGas -= (i == n-1 ? dist : stations[i+1].pos) - stations[i].pos;
	}

	if (curGas < 0) {
		printf("-1\n");
	} else {
		printf("%lld\n", cost);
	}
}
