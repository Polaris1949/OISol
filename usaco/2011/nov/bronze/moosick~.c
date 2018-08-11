#include <stdio.h>
#define MAX_N 20000
#define MAX_C 10

int A[MAX_N], B[MAX_C], M[MAX_N];
int N, C;

void translate_so_min_is_zero(int *X)
{
  int i, min;

  for (i=0; i<C; i++)
    if (i==0 || X[i]<min)
      min = X[i];
  for (i=0; i<C; i++)
    X[i] -= min;
}

void sort(int *X)
{
  int i, j, tmp;

  for (i=0; i<C; i++)
    for (j=0; j<C-1; j++)
      if (X[i] > X[j]) {
	tmp = X[i];
	X[i] = X[j];
	X[j] = tmp;
      }
}

/* Return 1 if match at index idx */
int match(int idx)
{
  int P[MAX_C], Q[MAX_C];
  int i, j, min, tmp;

  for (i=0; i<C; i++) {
    P[i] = A[i+idx];
    Q[i] = B[i];
  }

  translate_so_min_is_zero(P);
  translate_so_min_is_zero(Q);
  sort(P);
  sort(Q);

  for (i=0; i<C; i++)
    if (P[i] != Q[i])
      return 0;
  return 1;
}

int main(void)
{
  int i, total = 0;

  freopen ("moosick.in", "r", stdin);
  freopen ("moosick.out", "w", stdout);

  scanf ("%d", &N);
  for (i=0; i<N; i++)
    scanf ("%d", &A[i]);
  scanf ("%d", &C);
  for (i=0; i<C; i++)
    scanf ("%d", &B[i]);

  for (i=0; i+C<=N; i++) {
    M[i] = match(i);
    total += M[i];
  }

  printf ("%d\n", total);
  for (i=0; i<N; i++)
    if (M[i])
      printf ("%d\n", i+1);

  return 0;
}
