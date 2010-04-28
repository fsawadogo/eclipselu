/*
ID: eclipse5
PROG: nocows 
LANG: C++
*/

#include <cstdio>
#include <cstring>

int n,k;
long f[201][101];

void init()
{
	scanf("%d%d",&n,&k);
	memset(f,0,sizeof(f));
}	

void dp()
{
	int i,j,l;
	for (i=1;i<=k;i++)
		f[1][i] = 1;
	for (j=1;j<=k;j++)
		for (i=1;i<=n;i+=2)
			for (l=1;l<=i-2;l++)
			{
				f[i][j]+=f[l][j-1]*f[i-1-l][j-1];
				f[i][j]%=9901;
			}
}

int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	init();
	dp();
	printf("%ld\n",(f[n][k]-f[n][k-1]+9901)%9901);
	return 0;
}