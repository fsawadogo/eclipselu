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

int cal(char *s)			//nice evaluation
{
	int term, sign, sum;
	char *p;

	sign = 1;
	term = 0;
	sum = 0;
	for(p=s; *p; p++) {
		switch(*p){
		case '+':
		case '-':
			sum += sign*term;
			term = 0;
			sign = *p == '+' ? 1 : -1;
			break;
		case ' ':
			break;
		default:    /* digit */
			term = term*10 + *p-'0';
		}
	}
	sum += sign*term;
	return sum;
}


void dfs(int depth,char exp[])		//generating all possible expressions
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
		dfs(depth+1,str);		//' '
		str[len]='+';
		dfs(depth+1,str);       //'+'
		str[len]='-';
		dfs(depth+1,str);		//'-'
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