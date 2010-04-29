/*
ID: eclipse5
PROG: money
LANG: C++
*/

#include <cstdio>
#include <cstring>

int v,n;
int t[26];		//money system
long long f[10001];	

//input may contain duplicate coin types
//so you may need to optimize init subroutine
void init()		
{
	int i;
	scanf("%d%d",&v,&n);
	for (i=1;i<=v;i++)
		scanf("%d",&t[i]);
	memset(f,0,sizeof(f));
}

void dp()	//two dimensional dp will get time limit exceeded
{
	int i,j;
	for (i=0;i*t[1]<=n;i++)
		f[i*t[1]]=1;
	for (i=2;i<=v;i++)
		for (j=0;j<=n;j++)
			if (j-t[i]>=0)
				f[j]+=f[j-t[i]];
	printf("%lld\n",f[n]);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	init();
	dp();
	return 0;
}