#include <stdio.h>

#define MAX_M 10000
#define MAX_N 10
#define INF 1000000000

int best[MAX_M+1][MAX_N+1];
int A[MAX_M+1];

int main(void)
{
  int M, N, i, j, k;

  freopen ("tilechng.in", "r", stdin);
  freopen ("tilechng.out", "w", stdout);

  scanf ("%d %d", &N, &M);
  for (i=1; i<=N; i++)
    scanf ("%d", &A[i]);

  for (i=1; i<=M; i++)
    best[i][0] = INF;

  for (j=1; j<=N; j++)
    for (i=0; i<=M; i++) {
      best[i][j] = INF;
      for (k=1; k*k<=i; k++)
      if ((A[j]-k)*(A[j]-k) + best[i-k*k][j-1] < best[i][j])
        best[i][j] = (A[j]-k)*(A[j]-k) + best[i-k*k][j-1];
    }

  if (best[M][N]==INF)
    printf ("-1\n");
  else
    printf ("%d\n", best[M][N]);

  return 0;
}
