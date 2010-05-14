/*
ID: eclipse5
PROG: humble
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <climits>

int N,K;
int s[100];
int hum[100001];
int last[100];		//speed up search

void init()
{
	int i;
	scanf("%d%d",&K,&N);
	for (i=0;i<K;i++)
		scanf("%d",&s[i]);
	memset(last,0,sizeof(last));
}

void solve()
{
	int i,j,k;
	int next,temp;
	hum[0]=1;

	for (i=1;i<=N;i++)
	{
		next=INT_MAX;
		for (j=0;j<K;j++)
			for (k=last[j];k<i;k++)
			{
				temp=s[j]*hum[k];
				if (temp>hum[i-1])
				{
					if (temp<next)
						next=temp;
					last[j]=k;
					break;
				}
			}
		hum[i]=next;
	}	
	printf("%d\n",hum[N]);
}

int main()
{
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	init();
	solve();
	return 0;
}