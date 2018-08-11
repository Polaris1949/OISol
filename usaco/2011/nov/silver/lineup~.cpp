#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
using namespace std;

typedef struct {
  int loc, id;
} Cow;

int sort_cows(const void* v1, const void *v2) {
  Cow *c1 = (Cow*)v1, *c2 = (Cow*)v2;
  return c1->loc>c2->loc;
}

int main() {
  freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
  int num_IDS, N, i, num_in_map = 0, A[50000], IDS[50000], start, end, min;
  Cow cows[50000];
  map<int, int> breeds;
  set<int> ID_set;

  scanf("%d", &N);
  for(i=0; i<N; i++) {
    scanf("%d %d", &cows[i].loc, &cows[i].id);
    ID_set.insert(cows[i].id);
    breeds[cows[i].id] = 0;
  }

  qsort(cows, N, sizeof(Cow), sort_cows);

  num_IDS = ID_set.size();

  start = 0;
  end = 0;
  min = 1<<30;

  while(1) {
    while(num_in_map!=num_IDS && end<N) {
      if(breeds[cows[end].id]==0)
        num_in_map++;
      breeds[cows[end++].id]++;
    }
    if(end==N && num_in_map!=num_IDS)
      break;

    while(breeds[cows[start].id]>1)
      breeds[cows[start++].id]--;

    if(cows[end-1].loc-cows[start].loc<min) min = cows[end-1].loc-cows[start].loc;
    breeds[cows[start++].id]--;
    num_in_map--;
  }

  printf("%d\n", min);

  return 0;
}
