#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define N_MAX 10005

struct cow {
	int g, d;

	// comparison function that will be used to make a max-heap keyed by g
	bool operator<(cow const& c) const {
		return g < c.g;
	}
};
cow cows[N_MAX];

// comparison function used to sort in decreasing order of d
inline bool sort_by_d(cow const& a, cow const& b) {
	return a.d > b.d;
}

int main() {
	freopen("msched.in", "r", stdin);
	freopen("msched.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cows[i].g);
		scanf("%d", &cows[i].d);
	}

	sort(cows, cows + n, sort_by_d);

	// Index of the next cow to become available (when t decreases
	// below a cow's deadline d, we say the cow becomes available)
	int curcow = 0;

	// Total milk output
	int total = 0;

	// Stores the currently available cows that haven't been scheduled yet
	priority_queue<cow> q;

	for (int t = 10000; t >= 1; t--) {
		// Find all the cows that become available at time t.
		while (curcow < n && t <= cows[curcow].d) {
			q.push(cows[curcow]);
			curcow++;
		}

		// If any cow is available, take the best one and schedule it
		// for time t, adding its output to the total.
		if (q.size() > 0) {
			total += q.top().g;
			q.pop();
		}
	}

	printf("%d\n", total);
}
