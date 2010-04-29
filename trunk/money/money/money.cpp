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
bool used[10001];

//input may contain duplicate coin types
//so you may need to optimize init subroutine
void init()		
{
	int i,cnt,num;
	memset(used,false,sizeof(used));
	scanf("%d%d",&cnt,&n);
	v=0;
	for (i=0;i<cnt;i++)
	{
		scanf("%d",&num);
		if (num<=n&&!used[num])
		{
			used[num]=true;
			t[++v]=num;
		}
	}
	memset(f,0,sizeof(f));
}

void dp()	//two dimensional dp will get time limit exceeded
{
	int i,j;
	f[0]=1;
	for (i=1;i<=v;i++)
		for (j=t[i];j<=n;j++)
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