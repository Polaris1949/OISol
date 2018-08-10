#include <cmath>
#include <cstdio>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	
	if (n==0) {
		printf("0\n");
		return 0;
	}
	
	if (n<0) {
		printf("-");
		n=abs(n);
	}
	
	while (n%10==0) n/=10;
	
	while (n!=0) {
		printf("%d", n%10);
		n/=10;
	}
	
	printf("\n");
	return 0;
}
