/*
ID: eclipse5
PROG: money
LANG: C++
*/

#include <cstdio>
#include <cstring>

int v,n;
int t[26];		//money system
long long f[26][10001];	

void init()
{
	int i;
	scanf("%d%d",&v,&n);
	for (i=1;i<=v;i++)
		scanf("%d",&t[i]);
	memset(f,0,sizeof(f));
}

void dp()
{
	int i,j,k;
	for (i=0;i<=v;i++)
		f[i][0]=1;
	for (i=1;i<=v;i++)
		for (j=1;j<=n;j++)
			for (k=0;k<=j/t[i];k++)
				f[i][j]+=f[i-1][j-k*t[i]];
	printf("%lld\n",f[v][n]);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	init();
	dp();
	return 0;
}