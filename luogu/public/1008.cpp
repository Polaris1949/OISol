#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int i;
	for (i=1; i<=9; i++) {
		v.push_back(i);
	}
	
	int a, b, c;
	do {
		a=v[0]*100+v[1]*10+v[2];
		b=v[3]*100+v[4]*10+v[5];
		c=v[6]*100+v[7]*10+v[8];
		if (a*2==b && a*3==c) printf("%d %d %d\n", a, b, c);
	} while(next_permutation(v.begin(), v.end()));
	
	return 0;
}
