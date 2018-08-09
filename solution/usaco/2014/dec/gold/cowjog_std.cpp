#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  vector<long long> A;
  for (int i = 0; i < N; i++) {
    long long x, s;
    cin >> x >> s;
    x = -(x + s * T);

    if (A.empty() || x >= A.back()) {
      A.push_back(x);
    } else {
      *upper_bound(A.begin(), A.end(), x) = x;
    }
  }

  cout << A.size() << endl;
  return 0;
}
