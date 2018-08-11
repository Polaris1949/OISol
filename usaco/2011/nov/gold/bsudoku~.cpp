#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define INF 100

bool A[9][9]; /* The original sudoku board. */

int memo[9][9][1<<9][1<<3][2]; /* Cache of already computed values. */

int solve(int r, int c, int mc, int mb, bool p) {
  if(r == 9) {
    /* If we finished the last row make sure the columns have even parity and
     * we're done. */
    return mc ? INF : 0;
  }
  if(c == 9) {
    /* If we finished a column make sure the row has even parity. */
    if(p) return INF;

    /* Additionally if we finished a third row make sure the boxes have even
     * parity. */
    if(r % 3 == 2 && mb) return INF;

    /* Otherwise move to the beginning of the next row. */
    return solve(r + 1, 0, mc, mb, 0);
  }

  /* Check if we already figured out this state. */
  int& ref = memo[r][c][mc][mb][p];
  if(ref != -1) return ref;

  /* Try setting the cell to 1. */
  ref = !A[r][c] + solve(r, c + 1, mc ^ 1 << c, mb ^ 1 << c / 3, !p);

  /* Try setting the cell to 0. */
  ref = min(ref, A[r][c] + solve(r, c + 1, mc, mb, p));

  return ref;
}

int main() {
  freopen("bsudoku.in", "r", stdin);
  freopen("bsudoku.out", "w", stdout);

  /* Read in the input into A. */
  for(int i = 0; i < 9; i++) {
    string S; cin >> S;
    for(int j = 0; j < 9; j++) A[i][j] = S[j] == '1';
  }

  memset(memo, -1, sizeof(memo));
  cout << solve(0, 0, 0, 0, 0) << endl;
}
