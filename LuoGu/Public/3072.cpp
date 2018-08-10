#include <iostream>
#include <unordered_map>
#define INF 1000000
using namespace std;

const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
unordered_map<int,unordered_map<int,bool> > mat;
int ans,sy=INF,sx=INF,d;

int main()
{
	int n,i,x,y;
	cin >> n;

	for (i=0; i<n; ++i)
	{
		cin >> x >> y;
		mat[y][x]=true;
		if (y<sy || (y==sy && x<sx)) {sy=y; sx=x;}
	}

	y=sy; x=sx;


	do
	{
		y+=dir[d][0];
        x+=dir[d][1];
        ++ans;

		for (d=(d+3)%4; ; d=(d+1)%4)
			if ((d==0 && mat[y][x]) || (d==1 && mat[y-1][x]) ||
			        (d==2 && mat[y-1][x-1]) || (d==3 && mat[y][x-1]))
		        break;
	}
	while (y!=sy || x!=sx);

	cout << ans << endl;
    return 0;
}
