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
char nwse[5] = "NESW";

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
	while(cx1!=fx1||cy1!=fy1)
	{
		//printf("cow:(%d,%d)%c farmer:(%d,%d)%c\n",cx1,cy1,nwse[dc],fx1,fy1,nwse[df]);
		move(cx1,cy1,dc);
		move(fx1,fy1,df);		
		count++;
		if (count>20000)
			break;
	}
	//printf("cow:(%d,%d)%c farmer:(%d,%d)%c\n",cx1,cy1,nwse[dc],fx1,fy1,nwse[df]);
	if (count>20000)
		printf("0\n");
	else
		printf("%d\n",count);
}

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	init();
	solve();
	return 0;
}