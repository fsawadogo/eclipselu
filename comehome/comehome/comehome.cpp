/*
ID: eclipse5
PROG: comehome
LANG: C++
*/

#include <cstdio>
#include <cctype>
#include <cstring>

const int maxn = 52;
const int infinity = 99999999;

int p;
int g[maxn][maxn];
int distance[maxn];

void init()
{
	char c1,c2;
	int len,i,j,k1,k2;

	for (i=0;i<maxn;i++)
		for (j=0;j<maxn;j++)
			g[i][j]=(i==j?0:infinity);

	scanf("%d\n",&p);
	for (i=0;i<p;i++)
	{
		scanf("%c %c %d\n",&c1,&c2,&len);
		if (isupper(c1))		
			k1=c1-'A';
		else if (islower(c1))
			k1=c1-'a'+26;
		if (isupper(c2))		
			k2=c2-'A';
		else if (islower(c2))
			k2=c2-'a'+26;

		if (len<g[k1][k2])
			g[k1][k2]=g[k2][k1]=len;
	}
}

void getmin(int *dist,bool *visit,int &k)
{
	int i,mincost=infinity;
	for (i=0;i<maxn;i++)
		if(!visit[i]&&dist[i]<mincost)
		{
			mincost=dist[i];
			k=i;
		}
}	

void dijkstra(int src)
{
	bool visited[maxn];
	int i,j,k;

	for (i=0;i<maxn;i++)
	{
		distance[i]=infinity;
		visited[i]=false;
	}
	distance[src]=0;
	for (i=0;i<maxn;i++)
	{
		getmin(distance,visited,k);
		visited[k]=true;
		for (j=0;j<maxn;j++)
			if(!visited[j]&&g[k][j]<infinity&&distance[k]+g[k][j]<distance[j])
				distance[j]=distance[k]+g[k][j];
	}
}

void solve()
{
	int i,j,ans=infinity;

	dijkstra('Z'-'A');
	for (i=0;i<25;i++)
		if(distance[i]<ans)
		{
			j=i;
			ans=distance[i];
		}
	printf("%c %d\n",j+'A',ans);
}

int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	init();
	solve();
	return 0;
}