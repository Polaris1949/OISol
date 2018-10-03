#include <iostream>

int n, a[9][9], d[18][9][9];

inline int max(int a, int b, int c, int d)
{
  return std::max(std::max(a, b), std::max(c, d));
}

int main()
{
  int i, j, k, x, y, v;
  std::cin >> n;

  while (true)
    {
      std::cin >> x >> y >> v;
      if (x == 0 && y == 0 && v == 0)
        break;
      a[--x][--y] = v;
    }

  d[0][0][0] = a[0][0];

  for (i = 0; i < n * 2; ++i)
    for (j = 0; j <= i && j < n; ++j)
      for (k = 0; k <= i && k < n; ++k)
        {
          if (i == 0 && j == 0 && k == 0)
            continue;
          d[i][j][k] = a[j][i - j] + a[k][i - k]
                       + max(d[i - 1][j][k], d[i - 1][j - 1][k - 1],
                             d[i - 1][j - 1][k], d[i - 1][j][k - 1]);
          if (j == k)
            d[i][j][k] -= a[j][i - j];
        }

  std::cout << d[(n - 1) * 2][n - 1][n - 1] << '\n';
  return 0;
}
