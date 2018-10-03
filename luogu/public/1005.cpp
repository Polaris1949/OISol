#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

class big
{
public:
std::vector<short> num;

big()
{
  num.push_back(0);
}

big(int x)
{
  while (x)
    {
      num.push_back(x % 10);
      x /= 10;
    }
}

bool operator <(const big& x) const
{
  if (len == x.len)
    {
      for (size_t i = len - 1; i >= 0; i--)
        {
          if (num[i] < x.num[i])
            return 0;
          if (num[i] > x.num[i])
            return 1;
        }
    }
else return len < x.len;
}

big operator +(const big& x)
{
  big ans;

  ans.len = std::max(len, x.len);

  for (int i = 0; i < ans.len; i++)
    {
      ans.num[i] += num[i] + x.num[i];
      ans.num[i + 1] += ans.num[i] / 10;
      ans.num[i] %= 10;
    }

  if (ans.num[ans.len])
    ans.len++;
  return ans;
}

big operator *(const big& x)
{
  big ans;

  ans.len = len + x.len;

  for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < x.len; j++)
        {
          ans.num[i + j] += num[i] * x.num[j];
          ans.num[i + j + 1] += ans.num[i + j] / 10;
          ans.num[i + j] %= 10;
        }
    }

  if (ans.num[ans.len - 1] == 0)
    ans.len--;
  return ans;
}

big operator *(int x)
{
  return (*this) * (big(x));
}

void write()
{
  if (len == 0)
    printf("0");
  for (int i = len - 1; i >= 0; i--)
    printf("%d", num[i]);
  printf("\n");
}
};

int n, m;
int a[85];
big ans;
big f[85][85];
big tm[85];

int main()
{
  int i, j, k;
  std::cin >> n >> m;

  tm[0] = 1;
  for (i = 1; i <= m; i++)
    tm[i] = tm[i - 1], tm[i] = tm[i] * 2;

  ans = 0;
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= m; j++)
        std::cin >> a[j];

      for (j = 1; j <= m; j++)
        f[j][j] = tm[m] * a[j];

      for (j = 1; j < m; j++)
        {
          for (k = 1; k < m; k++)
            {
              if (j + k > m)
                break;
              big t1 = tm[m - j] * a[k] + f[k + 1][k + j];
              big t2 = tm[m - j] * a[k + j] + f[k][k + j - 1];
              if (t1 > t2)
                f[k][k + j] = t1;
              else
                f[k][k + j] = t2;
            }
        }

      ans = ans + f[1][m];
    }

  ans.write();
  return 0;
}
