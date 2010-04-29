/*
ID: eclipse5
PROG: nocows 
LANG: C++
*/

#include <cstdio>
#include <cstring>

int n,k;
long f[101][201];

void init()
{
	scanf("%d%d",&n,&k);
	memset(f,0,sizeof(f));
}	

void dp()
{
	int i,j,l;
	for (i=1;i<=k;i++)
		f[i][1] = 1;
	for (i=1;i<=k;i++)
		for (j=1;j<=n;j+=2)
			for (l=1;l<=j-2;l++)
			{
				f[i][j]+=f[i-1][l]*f[i-1][j-1-l];
				f[i][j]%=9901;			//mod 9901 in case of overflow
			}
}

int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	init();
	dp();
	//f[k-1][n] could be greater than f[k][n]
	printf("%ld\n",(f[k][n]-f[k-1][n]+9901)%9901);	
	return 0;
}