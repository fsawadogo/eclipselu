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
node arr[maxn];		//nodes
int father[maxn];	//disjoint set
char matrix[maxn][maxn];	//adjacent matrix
double d[maxn][maxn];		//shortest path length
int n;					

inline double len(int i,int j)	//calculate length
{
	return sqrt((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)+(arr[i].y-arr[j].y)*(arr[i].y-arr[j].y));
}

int getfather(int k)
{
	if (father[k]==k) return k;
	father[k] = getfather(father[k]);
	return father[k];
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
		father[i]=i;
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			d[i][j]=(i==j?0:infinity);		
	}

	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (matrix[i][j]=='1')
			{
				d[i][j]=d[j][i]=len(i,j);			
				if (getfather(i)!=getfather(j))
					father[getfather(i)]=getfather(j);
			}
}

void floyd()		//Floyd-Warshall
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
	double temp1,temp2,newdiam,ans=infinity;
	double mdist[maxn];	//mdist[i]: max length of shortest path len of (i,j), j is connected to i
	double diam[maxn];		//diam[i]: diameters of all connected components, component number is the 
							//father of the disjoint set
	for (i=0;i<n;i++)	
	{
		mdist[i]=0;
		diam[i]=-1;
	}
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (d[i][j]!=infinity&&d[i][j]>mdist[i])
			{
				mdist[i]=d[i][j];
				if (mdist[i]>diam[getfather(i)])
					diam[getfather(i)]=mdist[i];
			}

	//newdiam = max(len(i,j)+mdist[i]+mdist[j],diam[compno(i)],diam[compno(j)])
	//compno==getfather
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (d[i][j]==infinity)
			{
				temp1 = len(i,j)+mdist[i]+mdist[j];
				temp2 = max(diam[getfather(i)],diam[getfather(j)]);
				newdiam = max(temp1,temp2);
				if (newdiam<ans)
					ans = newdiam;
			}	
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