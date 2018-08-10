#include <cstdio>
using namespace std;

int k;
double s;

int main() {
	scanf("%d", &k);
	int i=1;
	
	while (s<=k) {
		s+=(double)1/i; i++;
	}
	
	printf("%d\n", --i);
	return 0;
}
