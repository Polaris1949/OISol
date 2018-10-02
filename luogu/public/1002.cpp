#include <cmath>
#include <iostream>

long long f[30][30];

int main()
{
  int n, m, x, y, i, j;
  std::cin >> n >> m >> x >> y;

  ++n; ++m; ++x; ++y;
  f[0][1] = 1;

  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      {
        if ((abs(i - x) + abs(j - y) == 3) && (i != x) && (j != y)
            || (i == x && j == y))
          continue;
        else
          f[i][j] = f[i - 1][j] + f[i][j - 1];
      }

  std::cout << f[n][m] << '\n';
  return 0;
}
