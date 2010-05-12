/*
ID: eclipse5
PROG: agrinet
LANG: C++
*/

#include <cstdio>

const int maxn = 101;
const int infinity = 99999999;

int weight[maxn][maxn];
int n;

void init()
{
	int i,j;

	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			weight[i][j]=infinity;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			scanf("%d",&weight[i][j]);
}

//standard prim's algorithm
void prim(int src)		//starts from node src
{
	int i,j;
	int distance[maxn];	//distance[j]: distance from tree to node j
	int source[maxn];
	bool intree[maxn];
	int treesize,treecost;

	for (i=1;i<=n;i++)
	{
		distance[i]=infinity;
		intree[i]=false;
		source[i]=-1;
	}

	treesize=1;
	treecost=0;
	intree[src]=true;

	for (i=1;i<=n;i++)
		if (i!=src&&weight[src][i]<infinity)
		{
			distance[i]=weight[src][i];
			source[i]=src;
		}

		while(treesize<n)
		{
			//find node with minimum distance to tree
			int mincost = infinity;
			for (j=1;j<=n;j++)
				if (!intree[j]&&distance[j]<mincost)
				{
					mincost=distance[j];
					i=j;
				}

				//add edge source[i],i to tree
				treesize++;
				treecost+=distance[i];
				intree[i]=true;

				//update distance
				for (j=1;j<=n;j++)
					if (!intree[j]&&weight[i][j]<infinity&&weight[i][j]<distance[j])
					{
						distance[j]=weight[i][j];
						source[j]=i;
					}
		}

		printf("%d\n",treecost);
}
int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	init();
	prim(1);
	return 0;
}
