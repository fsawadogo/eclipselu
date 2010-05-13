/*
ID: eclipse5
PROG: inflate
LANG: C++
*/

#include <cstdio>

const int maxn = 10000;

int M,N;
int p[maxn],m[maxn];
int f[maxn];

void init()
{
	int i;
	scanf("%d%d",&M,&N);
	for (i=0;i<N;i++)
		scanf("%d%d",&p[i],&m[i]);
}

void dp()
{
	int i,j;
	for (i=0;i<=M;i++)
		f[i]=0;
	for (i=0;i<N;i++)
		for (j=m[i];j<=M;j++)
			if (f[j]<f[j-m[i]]+p[i])
				f[j]=f[j-m[i]]+p[i];

	printf("%d\n",f[M]);
}

int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	init();
	dp();
	return 0;
}