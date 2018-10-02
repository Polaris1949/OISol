#include <iostream>
#include <vector>

std::vector<int> a, b, g, k;

int main()
{
  int n, i, x, y;
  std::cin >> n;

  a.resize(n);
  b.resize(n);
  g.resize(n);
  k.resize(n);

  for (i = 0; i < n; ++i)
    std::cin >> a[i] >> b[i] >> g[i] >> k[i];

  std::cin >> x >> y;

  for (i = n - 1; i >= 0; --i)
    if (a[i] <= x && b[i] <= y && a[i] + g[i] >= x && b[i] + k[i] >= y)
      {
        std::cout << (i + 1) << '\n';
        return 0;
      }

  std::cout << "-1\n";
  return 0;
}
