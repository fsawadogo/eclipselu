/*
ID: eclipse5
PROG: cowtour
LANG: C++
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 150;
const double infinity = 1e20;

struct node
{
	double x,y;
};
node arr[maxn];
char matrix[maxn][maxn];
double d[maxn][maxn];
double maxcdist[maxn];
int n;

inline double len(double x,double y)
{
	return sqrt(x*x+y*y);
}

void init()
{
	int i,j;
	
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
		scanf("%lf%lf\n",&arr[i].x,&arr[i].y);	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			matrix[i][j]=getchar();
		getchar();
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			d[i][j]=(i==j?0:infinity);		
	}

	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (matrix[i][j]=='1')
				d[i][j]=d[j][i]=len(arr[i].x-arr[j].x,arr[i].y-arr[j].y);			
}

void floyd()
{
	int i,j,k;
		
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (d[i][k]+d[k][j]<d[i][j])
					d[i][j] = d[i][k]+d[k][j];
}

void solve()
{
	int i,j;
	double temp,ans=infinity;
	for (i=0;i<n;i++)
		maxcdist[i]=0;

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (d[i][j]!=infinity&&d[i][j]>maxcdist[i])
				maxcdist[i]=d[i][j];

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (d[i][j]==infinity)
			{
				temp = len(arr[i].x-arr[j].x,arr[i].y-arr[j].y)+maxcdist[i]+maxcdist[j];
				if (temp<ans)
					ans = temp;
			}
	for (i=0;i<n;i++)
		if (ans<maxcdist[i])
			ans = maxcdist[i];
	printf("%.6lf\n",ans);
}

int main()
{
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	init();
	floyd();
	solve();
	return 0;
}