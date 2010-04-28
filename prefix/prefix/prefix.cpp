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
int maxlen;
string s;
bool f[200001];

void init()
{
	string temp;
	n=0;
	maxlen=0;
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
	int i,j,k,len = s.length();
	int plen;
	bool tag;
	memset(f,false,sizeof(f));
	f[0] = true;
	for (i=1;i<=len;i++)
	{
		for (j=0;j<n;j++)
		{
			plen = prim[j].len;
			tag = true;
			if (i>=plen)
			{
				for (k=0;k<plen;k++)
					if (s[i-plen+k]!=prim[j].str[k])
					{
						tag = false;
						break;
					}
				if(tag)
					f[i] = f[i]||f[i-plen];
				if (f[i]&&i>maxlen)
					maxlen = i;
			}
		}
	}
	cout<<maxlen<<endl;
}

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	init();
	dp();
	return 0;
}