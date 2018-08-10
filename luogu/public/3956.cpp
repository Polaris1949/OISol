#include <cstdio>
#include <algorithm>
using namespace std;

const int cx[4]= {-1,1,0,0};
const int cy[4]= {0,0,-1,1};
int m,n,xx,yy,c,cc[105][105],dis[105][105];

void dfs(int x,int y,int ans,int flag)
{
	if(x<1||x>m||y<1||y>m||ans>=dis[x][y]) return;
	dis[x][y]=min(dis[x][y],ans);
	for(int i=0; i<4; i++)
	{
		int x1=x+cx[i],y1=y+cy[i];
		if(!cc[x][y]&&!cc[x1][y1]) continue;
		if(cc[x][y]&&!cc[x1][y1]) dfs(x1,y1,ans+2,cc[x][y]);
		else if(cc[x][y]&&cc[x1][y1]&&cc[x1][y1]!=cc[x][y]) dfs(x1,y1,ans+1,0);
		else if(cc[x][y]==cc[x1][y1]&&cc[x][y]&&cc[x1][y1]) dfs(x1,y1,ans,0);
		else if(!cc[x][y]&&cc[x1][y1]&&flag)
			if(flag!=cc[x1][y1]) dfs(x1,y1,ans+1,0);
			else dfs(x1,y1,ans,0);
	}
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0; i<n; i++) scanf("%d%d%d",&xx,&yy,&c),cc[xx][yy]=c+1;
	for(int i=0; i<105; i++)
		for(int j=0; j<105; j++) dis[i][j]=2100000000;
	dfs(1,1,0,0);
	if(dis[m][m]!=2100000000) printf("%d",dis[m][m]);
	else printf("%d",-1);
}
