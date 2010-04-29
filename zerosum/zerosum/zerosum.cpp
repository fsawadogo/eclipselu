/*
ID: eclipse5
PROG: zerosum
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int n;

int cal(char exp[])
{
	int i,len = strlen(exp);
	int sum = 0,op;
	char oprt = '+';
	i=0;
	while(i<len)
	{
		op=0;
		while(i<len&&exp[i]!='+'&&exp[i]!='-')
		{
			if (isdigit(exp[i]))
				op = op*10+exp[i]-'0';
			i++;
		}				
		if (oprt=='+')
			sum+=op;
		else
			sum-=op;
		if (exp[i]=='+'||exp[i]=='-')
			oprt=exp[i];
		i++;
	}
	return sum;
}

void dfs(int depth,char exp[])
{
    char str[20];
	int len;
	if (depth==n-1)
	{
		if (cal(exp)==0)
			printf("%s\n",exp);
	}
	else
	{
		strcpy(str,exp);
		len = strlen(str);
		str[len]=' ';
		str[len+1]='0'+depth+2;
		str[len+2]='\0';
		dfs(depth+1,str);
		str[len]='+';
		dfs(depth+1,str);
		str[len]='-';
		dfs(depth+1,str);		
	}
}

int main()
{
	freopen("zerosum.in","r",stdin);	
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	dfs(0,"1");	
	return 0;
}