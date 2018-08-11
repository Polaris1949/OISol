#include <stdio.h>
#define MAX_N 50
#define MAX_M 50

char G[MAX_N][MAX_M+1];
int N, M;

int label(int r, int c, char ch)
{
  if (G[r][c]!='X') return;
  G[r][c] = ch;
  if (r>0) label(r-1,c,ch);
  if (c>0) label(r,c-1,ch);
  if (r<N-1) label(r+1,c,ch);
  if (c<M-1) label(r,c+1,ch);
}

int abs(x)
{
  if (x>=0) return x;
  return -x;
}

int mindist(void)
{
  int r1, r2, c1, c2, min=MAX_N+MAX_M;

  for (r1=0; r1<N; r1++)
    for (c1=0; c1<M; c1++)
      if (G[r1][c1]=='1')
	for (r2=0; r2<N; r2++)
	  for (c2=0; c2<M; c2++)
	    if (G[r2][c2]=='2')
	      if (abs(r1-r2) + abs(c1-c2) < min)
		min = abs(r1-r2) + abs(c1-c2);
  return min - 1;
}

int main(void)
{
  int r, c;
  char ch='0';

  freopen ("pageant.in", "r", stdin);
  freopen ("pageant.out", "w", stdout);

  scanf ("%d %d", &N, &M);
  for (r=0; r<N; r++)
    scanf ("%s", &G[r]);

  for (r=0; r<N; r++)
    for (c=0; c<M; c++)
      if (G[r][c] == 'X')
	label(r,c,++ch);

  printf ("%d\n", mindist());
  return 0;
}
