#include <stdio.h>
#include <stdlib.h>
char cow[50][50];
int N, M, spots[3][2500][2], counts[3];

void mark_spot(int a, int b, int num) {
  if(a<0 || b<0 || a==N || b==M || cow[a][b]!='X') return;
  cow[a][b] = 'V';
  spots[num][counts[num]][0] = a;
  spots[num][counts[num]++][1] = b;
  mark_spot(a-1, b, num);
  mark_spot(a+1, b, num);
  mark_spot(a, b-1, num);
  mark_spot(a, b+1, num);
}

int l1_dist(int a1, int b1, int a2, int b2) {
  return abs(a1-a2)+abs(b1-b2);
}

int try_point(int a, int b) {
  if(cow[a][b]=='V') return 1000;
  int i, j, ans = 0;
  for(i=0; i<3; i++) {
    int min = 101;
    for(j=0; j<counts[i]; j++) {
      int t = l1_dist(spots[i][j][0], spots[i][j][1], a, b)-1;
      if(t<min) min = t;
    }
    ans+=min;
  }
  return ans+1;
}

int main() {
  freopen("pageant.in", "r", stdin); freopen("pageant.out", "w", stdout);
  scanf("%d %d", &N, &M);
  int i, min = 301, j, num_spots = 0, mins[3], k;

  for(i=0; i<N; i++)
    scanf("%s", cow[i]);

  for(i=0; i<N; i++)
    for(j=0; j<M; j++)
      if(cow[i][j]=='X')
        mark_spot(i,j,num_spots++);

  for(i=0; i<N; i++)
    for(j=0; j<M; j++) {
      int t = try_point(i,j);
      if(t<min) min = t;
    }

  for(i=0; i<3; i++) {
    mins[i]=101;
    for(j=0; j<counts[i]; j++)
      for(k=0; k<counts[(i+1)%3]; k++) {
        int t = l1_dist(spots[i][j][0], spots[i][j][1], spots[(i+1)%3][k][0], spots[(i+1)%3][k][1])-1;
        if(t<mins[i]) mins[i] = t;
      }
  }

  for(i=0; i<3; i++)
    if(mins[i]+mins[(i+1)%3]<min)
      min = mins[i]+mins[(i+1)%3];

  printf("%d\n", min);

  return 0;
}
