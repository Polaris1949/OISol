#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_to_base_n(char *s, int n)
{
  int i = strlen(s), t=0, p=1;
  while (i) {
    i--;
    t += p * (s[i] - '0');
    p = p * n;
  }
  return t;
}

int main(void)
{
  char A[100], B[100];
  int lenA, lenB, i, j, k;
  FILE *fp;

  fp = fopen ("digits.in", "r");
  fscanf (fp, "%s %s", A, B);
  fclose (fp);

  lenA = strlen(A);
  lenB = strlen(B);

  for (i=0; i<lenA; i++)
    for (j=0; j<lenB; j++)
      for (k=1; k<=2; k++) {
	A[i]=((A[i]-'0')+1)%2+'0';
	B[j]=((B[j]-'0')+k)%3+'0';
	if (convert_to_base_n(A,2) == convert_to_base_n(B,3)) {
	  fp = fopen ("digits.out", "w");
	  fprintf (fp, "%d\n", convert_to_base_n(A,2));
 	  fclose (fp);
	  return 0;
	}
	A[i]=((A[i]-'0')+1)%2+'0';
	B[j]=((B[j]-'0')+3-k)%3+'0';
      }
  return 0;
}
