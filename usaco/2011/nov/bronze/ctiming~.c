#include <stdio.h>

int total_mins(int d, int h, int m)
{
  return d * 24 * 60 + h * 60 + m;
}

int main(void)
{
  int d, h, m;

  freopen ("ctiming.in", "r", stdin);
  freopen ("ctiming.out", "w", stdout);

  scanf ("%d %d %d", &d, &h, &m);

  if (total_mins(d,h,m) < total_mins(11,11,11))
    printf ("-1\n");
  else
    printf ("%d\n", total_mins(d,h,m) - total_mins(11,11,11));

  return 0;
}
