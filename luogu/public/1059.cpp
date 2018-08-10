#include <cstdio>
#include <iostream>
using namespace std;

int a[101];
bool b[1001];

int main() {
    int n, i, m=0, f=1;
    
    scanf("%d", &n);
    
    for (i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]=true;
    }
    
    for (i=1; i<=1000; i++) {
        if (b[i]==true) {
            m++;
        }
    }
    printf("%d\n", m);
    
    for (i=1; i<=1000; i++) {
        if (b[i]==true) {
            if (f<m) {
                printf("%d ", i);
                f++;
            }
            else {
                printf("%d\n", i);
                break;
            }
        }
    }
    
    return 0;
}
