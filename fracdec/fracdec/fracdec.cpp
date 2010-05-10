/*
ID: eclipse5
PROG: fracdec
LANG: C++
*/

#include <cstdio>
#include <cmath>
#include <cstring>

//比较繁琐的一道题
struct node
{
	int q,r;				//q商，r余数
};
int a,b,c;
bool rem[100000],tag;		//rem[i]表示余数i是否出现过
node arr[100000];			
int n,l;					//l找出循环节的左边边界

int gcd(int a,int b)
{
	if (a==0)
		return b;
	if (a>b)
		gcd(b,a);
	else 
		gcd(b%a,a);
}

void init()
{   
	int i,g;
	scanf("%d%d",&a,&b);
	g=gcd(a,b);
	a/=g;
	b/=g;
	c=a/b;
	a=a%b;
	
	n=0;
	memset(rem,0,sizeof(rem));
}

void newline(int &cnt)
{
	cnt++;
	if (cnt%76==0)
	{
		printf("\n");
		cnt=0;
	}
}

void solve()
{
	int i,m,num;
	tag=false;
	num = a;
	while (num)
	{
		m=num/b;
		arr[n].q=m;
		arr[n++].r=num%b;
		num%=b;
		if (rem[num]==true)
		{
			tag=true;			
			break;
		}
		else
			rem[num]=true;
		num*=10;
	}	
}

void output()
{
	int i,cnt;			//cnt当前输出的字符数
	if (n==0)
	{
		printf("%d.0\n",c);
		return;
	}

	cnt=1;
	if (c>0)
		cnt+=int(log10(double(c)))+1;
	else
		cnt++;
	printf("%d.",c);

	if (tag)		//有循环节
	{
		if (arr[n-1].r==b)	//纯循环小数,例如0.(3) 0.(142857)
		{
			printf("(");
			newline(cnt);
			for (i=1;i<n-1;i++)
			{
				printf("%d",arr[i].q);
				newline(cnt);
			}
			printf(")");
			newline(cnt);
		}		
		else				//混循环小数,例如0.1(78)
		{
			for (l=n-2;l>=0&&arr[l].r!=arr[n-1].r;l--)	;	//找左边界

			for (i=1;i<=l;i++)
			{
				printf("%d",arr[i].q);
				newline(cnt);
			}
			printf("(");
			newline(cnt);
			for (i=l+1;i<n;i++)
			{
				printf("%d",arr[i].q);
				newline(cnt);
			}
			printf(")");
			newline(cnt);			
		}

	}
	else	//无循环节
	{
		for (i=1;i<n;i++)
		{
			printf("%d",arr[i].q);
			newline(cnt);
		}
	}
	printf("\n");
}

int main()
{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	init();
	solve();
	output();
	return 0;
}