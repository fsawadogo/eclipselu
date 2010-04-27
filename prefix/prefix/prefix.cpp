/*
ID: eclipse5
PROG: prefix
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

struct node
{
	string str;
	int len;
};
node prim[201];
int n;
string s;
int f[200001];

void init()
{
	string temp;
	n=0;
	while(cin>>prim[n].str&&prim[n].str!=".")
	{
		prim[n].len = prim[n].str.length();
		n++;
	}
	s="";
	while(cin>>temp)
		if (temp!="\n")
			s+=temp;
}

void dp()
{
	int i,j,len = s.length();
	int off;
	memset(f,0,sizeof(f));

	for (i=len;i>=0;i--)
	{
		for (j=0;j<n;j++)
		{
			off = i-prim[j].len;
			if (off>=0&&s.substr(off,prim[j].len)==prim[j].str)
				f[off] = max(prim[j].len + f[i], f[off]);
		}
	}
	cout<<f[0]<<endl;
}

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	init();
	dp();
	return 0;
}