/*
ID: eclipse5
PROG: maze1
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

const int infinity = 99999999;

int w,h;
char maze[2*38+1][2*100+1];
int g[38][100][38][100];
int exits[3800][2],ecnt=0;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};   

bool isexit(int i,int j,int d)
{
	switch(d)
	{
	case 0:if (i==0) return true;break;
	case 1:if (j==w-1) return true;break;
	case 2:if (i==h-1) return true;break;
	case 3:if (j==0) return true;break;
	}
	return false;
}

void init()		//input data and create graph
{
	int i,j,k,l;
	int x,y,x1,y1;
	scanf("%d%d\n",&w,&h);
	for (i=0;i<2*h+1;i++)
		fgets(maze[i],201,stdin);
	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
			for (k=0;k<h;k++)
				for (l=0;l<w;l++)
					g[i][j][k][l]=infinity;
	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
		{
			for (k=0;k<4;k++)
			{
				x=2*i+1+dir[k][0];
				y=2*j+1+dir[k][1];
				bool used = false;
				if (maze[x][y]==' ')
				{
					if (isexit(i,j,k))
					{
						if (!used)
						{

							exits[ecnt][0]=i;
							exits[ecnt][1]=j;
							ecnt++;
							used=true;	
						}
					}
					else
					{
						x1=i+dir[k][0];
						y1=j+dir[k][1];
						g[i][j][x1][y1]=g[x1][y1][i][j]=1;
					}
				}
			}
		}
}

void getmin(int &x,int &y,int dist[38][100],bool vis[38][100])
{
	int mincost = INT_MAX;
	int i,j;
	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
			if (!vis[i][j]&&dist[i][j]<mincost)
			{
				mincost = dist[i][j];
				x=i;
				y=j;
			}
}

int dijkstra(int srcx, int srcy, int destx, int desty)
{
	int distance[38][100];
	bool visited[38][100];
	int i,j,k,l;
	int x,y;
	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
		{
			distance[i][j]=infinity;
			visited[i][j]=false;
		}
	distance[srcx][srcy]=0;

	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
		{
			getmin(x,y,distance,visited);
			visited[x][y]=true;
			for (k=0;k<h;k++)
				for (l=0;l<w;l++)
					if (!visited[k][l]&&g[x][y][k][l]<infinity
						&&distance[x][y]+g[x][y][k][l]<distance[k][l])
						distance[k][l] = distance[x][y]+g[x][y][k][l];			
		}
	return distance[destx][desty];
}

void solve()
{
	int i,j,k,d;
	int ans = 0,minsteps;
	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
		{
			minsteps = infinity;
			for (k=0;k<ecnt;k++)
			{
				d = dijkstra(i,j,exits[k][0],exits[k][1]);
				if (d<minsteps)
					minsteps=d;
			}
			if (minsteps>ans)
				ans = minsteps;
		}
	printf("%d\n",ans+1);
}

int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	init();
	solve();
	return 0;
}