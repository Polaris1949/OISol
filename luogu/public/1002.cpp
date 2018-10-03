#include <cmath>
#include <iostream>

long long f[22][22];

inline long long g(int x, int y)
{
  return x < 0 ? y == 0 : f[x][y];
}

int main()
{
  int n, m, x, y, i, j;
  std::cin >> n >> m >> x >> y;

  ++n; ++m;

  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      {
        if (((abs(i - x) + abs(j - y) == 3) && (i != x) && (j != y))
            || (i == x && j == y))
          continue;
        else
          f[i][j] = g(i - 1, j) + g(i, j - 1);
      }

  std::cout << f[n - 1][m - 1] << '\n';
  return 0;
}
