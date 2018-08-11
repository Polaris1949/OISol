#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int main() {
  freopen("crowded.in", "r", stdin);
  freopen("crowded.out", "w", stdout);

  int N, D;
  cin >> N >> D;

  vector<pair<int, int> > A(N);
  for(int i = 0; i < N; i++)
    cin >> A[i].first >> A[i].second;

  sort(A.begin(), A.end());

  int result = 0;
  multiset<int> X, Y;
  int j = 0, k = 0;
  for(int i = 0; i < N; i++) {
    while(k < N && A[k].first <= A[i].first + D) {
      Y.insert(A[k++].second);
    }
    while(A[j].first + D < A[i].first) {
      X.erase(X.find(A[j++].second));
    }
    X.insert(A[i].second);

    if (*--X.end() >= 2 * A[i].second &&
        *--Y.end() >= 2 * A[i].second) {
      result++;
    }

    Y.erase(Y.find(A[i].second));
  }

  cout << result << endl;
  return 0;
}
