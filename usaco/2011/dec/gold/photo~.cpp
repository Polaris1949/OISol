#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

#define MAXN 20000

int A[MAXN];
map<int, int> pos[5];

bool cmp(int a, int b) {
  int f = 0;
  for(int i = 0; i < 5; i++) {
    f += pos[i][a] < pos[i][b];
  }
  return f > 2;
}

int main() {
  freopen("photo.in", "r", stdin);
  freopen("photo.out", "w", stdout);
  int N; cin >> N;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < N; j++) {
      int x; cin >> x;
      pos[i][x] = j;
      A[j] = x;
    }
  }
  sort(A, A + N, cmp);
  for(int i = 0; i < N; i++) {
    cout << A[i] << '\n';
  }
}
