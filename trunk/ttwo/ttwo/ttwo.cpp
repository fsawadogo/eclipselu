/*
ID: eclipse5
PROG: ttwo
LANG: C++
*/

#include <cstdio>
#include <cstring>

char grid[10][10];
int fx,fy,cx,cy;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void init()
{
	int i,j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			scanf("%c",&grid[i][j]);
			if (grid[i][j]=='F')
				fx=i,fy=j;
			else if (grid[i][j]=='C')
				cx=i,cy=j;
		}
		getchar();
	}
}

inline bool check(int x,int y)
{
	return ((x>=0&&x<10&&y>=0&&y<10)&&(grid[x][y]!='*'));
}

void move(int &x,int &y,int &d)
{
	int x1,y1;
	x1=x+dir[d][0];
	y1=y+dir[d][1];
	if (check(x1,y1))
	{
		x=x1;
		y=y1;
	}
	else
		d=(d+1)%4;
}

void solve()
{
	int count = 0;
	int cx1=cx,cy1=cy,fx1=fx,fy1=fy;
	int dc=0,df=0;
						
	while(count<160000&&(cx1!=fx1||cy1!=fy1))     //100 places,4 directions 400*400 different combinations
	{
		move(cx1,cy1,dc);
		move(fx1,fy1,df);		
		count++;		
	}
	if (cx1==fx1&&cy1==fy1)
		printf("%d\n",count);
	else
		printf("0\n");
}

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	init();
	solve();
	return 0;
}