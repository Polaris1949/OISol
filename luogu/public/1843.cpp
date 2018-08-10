#include <cstdio>
#include <iostream>
using namespace std;

int n, dx, dy, i, l, r, mid;
int a[500010];

bool ok(int mid)
{
int count, x, y, i;
   
   count = 0;
   
for(i=1; i<=n; i++) {
      x = a[i] - mid * dx;
      if (x<=0)  continue;
      y =x / dy;
      if (x % dy!=0)  y++;
      count += y;
      if (count > mid)  return false;
   }
   
if ( count <= mid )
    return true;
   else 
return false;
}

int main()
{
   
cin >> n >> dx >> dy;

for(i=1; i<=n; i++)  cin>>a[i];

l = 0;
r = 500010;

while (l!=r) {
mid = (l + r) >> 1;
       if ( ok(mid) ) 
           r = mid;
       else
l = mid + 1;
}

cout << l << endl;
 
return 0;
}
