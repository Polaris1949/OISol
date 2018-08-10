#include <cstdio>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
    int s=n, k=1;
	
    while (s-k>0) {
        s-=k; k++;
    }
	
    if (k%2) printf("%d/%d\n", k+1-s, s);
    else printf("%d/%d\n", s, k+1-s);
    
    return 0;
}
