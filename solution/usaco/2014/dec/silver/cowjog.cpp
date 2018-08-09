#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ll n, t;
  scanf("%lld %lld", &n, &t);
  vector<ll> S;
  for(ll i=0; i<n; i++) {
    ll x, s;
    scanf("%lld %lld\n", &x, &s);
    S.push_back(x + s*t);
  }

  ll ans = 1;
  ll slow = S[n-1];
  for(ll i=n-1; i>=0; i--) {
    if(S[i] < slow) { ans++; }
    slow = min(slow, S[i]);
  }
  printf("%lld\n", ans);
}
