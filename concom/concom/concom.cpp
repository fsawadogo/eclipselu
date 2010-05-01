/*
ID: eclipse5
PROG: concom
LANG: C++
*/

#include <cstdio>
#include <cstring>

const int maxn = 101;

int n;
int g[maxn][maxn];
int c[maxn][maxn];
bool con[maxn][maxn];

void init()
{
	int k,i,j,p;

	scanf("%d",&n);
	memset(g,0,sizeof(g));
	memset(con,false,sizeof(con));
	for (k=1;k<maxn;k++) con[k][k]=true;
	for (k=0;k<n;k++)
	{
		scanf("%d%d%d",&i,&j,&p);
		g[i][j]=p;
	}
	memcpy(c,g,sizeof(g));
}

void update(int a,int b)
{
	int k;
	con[a][b] = true;
	for (k=1;k<maxn;k++)
		c[a][k]+=c[b][k];
	for (k=1;k<maxn;k++)
		if (c[a][k]>50&&!con[a][k])
			update(a,k);
	for (k=1;k<maxn;k++)
		if (con[k][a]&&!con[k][b])
			update(k,b);
	for (k=1;k<=maxn;k++)
		if (con[b][k]&&!con[a][k])
			update(a,k);
}

void solve()
{
	int i,j;
	for (i=1;i<maxn;i++)
		for (j=1;j<maxn;j++)
			if (i!=j&&g[i][j]>50&&!con[i][j])
				update(i,j);
		
}

void output()
{
	int i,j;
	for (i=1;i<maxn;i++)
		for (j=1;j<maxn;j++)
			if (i!=j&&con[i][j])
				printf("%d %d\n",i,j);
}

int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	init();
	solve();
	output();
	return 0;
}