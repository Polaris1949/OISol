#include <cstdio>
#include <vector>
#include <queue>

#define PB push_back

using namespace std;

typedef long long ll;

vector<ll> D(ll st, const vector<vector<ll>>& E) {
  vector<ll> D(E.size(), -1);

  deque<ll> Q;
  D[st] = 0;
  Q.PB(st);
  while(!Q.empty()) {
    ll x = Q.front(); Q.pop_front();
    for(ll y : E[x]) {
      if(D[y] == -1) {
        D[y] = D[x]+1;
        Q.PB(y);
      }
    }
  }
  return D;
}

int main() {
  ll b, e, p, n, m;
  scanf("%lld %lld %lld %lld %lld", &b, &e, &p, &n, &m);
  vector<vector<ll>> E(n, vector<ll>());
  for(ll i=0; i<m; i++) {
    ll x, y;
    scanf("%lld %lld", &x, &y);
    x--; y--;
    E[x].PB(y);
    E[y].PB(x);
  }

  vector<ll> D0 = D(0, E);
  vector<ll> D1 = D(1, E);
  vector<ll> Dn = D(n-1, E);

  ll ans = ll(1000)*1000*1000*1000;
  for(ll meet=0; meet<n; meet++) {
    ans = min(ans, D0[meet]*b + D1[meet]*e + Dn[meet]*p);
  }
  printf("%lld\n", ans);
}
