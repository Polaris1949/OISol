#include <stdio.h>
#define MAX_N 10000

int N, K, A[MAX_N];

int main(void)
{
  int i, sum=0, answer=0;

  freopen ("haybales.in", "r", stdin);
  freopen ("haybales.out", "w", stdout);

  scanf ("%d", &N);
  for (i=0; i<N; i++) {
    scanf ("%d", &A[i]);
    sum += A[i];
  }

  K = sum / N;
  for (i=0; i<N; i++)
    if (A[i] > K)
      answer += A[i] - K;

  printf ("%d\n", answer);

  return 0;
}
