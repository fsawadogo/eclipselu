/*
ID: eclipse5
PROG: agrinet
LANG: C++
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 101;
const int infinity = 99999999;

struct edge
{
	int src,dest;
	int cost;
};

int father[maxn];
vector<struct edge> arr;
int n;

inline bool cmp(struct edge a,struct edge b)
{
	return a.cost<b.cost;
}

int getfather(int k)
{
	if (father[k]==k) return k;
	father[k]=getfather(father[k]);
	return father[k];
}

void init()
{
	int i,j,cost;
	struct edge e;
	scanf("%d",&n);

	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			scanf("%d",&cost);	
			if (i<j)
			{
				e.src=i;
				e.dest=j;
				e.cost=cost;
				arr.push_back(e);
			}
		}

	sort(arr.begin(),arr.end(),cmp);
	for (i=1;i<=n;i++)
		father[i]=i;
}

void kruskal() 
{
	int i,j;
	int treecost=0,edgecount=0;

	for (i=0;i<int(arr.size());i++)
	{
		if (getfather(arr[i].src)!=getfather(arr[i].dest))
		{
			treecost+=arr[i].cost;
			father[getfather(arr[i].src)]=getfather(arr[i].dest);
			edgecount++;
		}
		if (edgecount==n-1)
			break;
	}	
	printf("%d\n",treecost);
}

int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	init();
	kruskal();
	return 0;
}
