/*
LANG: C++
*/
#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

#define MAXN 1000

int N, M;
long long K;
string S;
int L[MAXN];
int R[MAXN];

pair get_next(pair v) {
  return make_pair((S[v.second] == 'L' ? L : R)[v.first], (v.second + 1) % M);
}

int main() {
  freopen("cruise.in", "r", stdin);
  freopen("cruise.out", "w", stdout);

  cin >> N >> M >> K;
  K *= M;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    L[i]--; R[i]--;
  }
  for(int i = 0; i < M; i++) {
    string s; cin >> s;
    S += s;
  }

  pair s0(0, 0);
  pair s1(0, 0);
  for(; K > 0; K--) {
    s0 = get_next(s0);
    s1 = get_next(get_next(s1));
    if(s0 == s1) {
      K--;
      break;
    }
  }
  if(K) {
    int rho = 1;
    for(s0 = get_next(s0); s0 != s1; rho++) {
      s0 = get_next(s0);
    }
    K %= rho;
  }
  for(; K > 0; K--) {
    s0 = get_next(s0);
  }
  cout << s0.first + 1 << endl;
  return 0;
}
