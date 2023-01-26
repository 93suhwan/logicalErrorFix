#include <iostream>
#include <stdarg.h>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(var,left,right) for(int var=left;var<right;var++)
#define FORd(var,left,right,step) for(int var=left;var>right;var+=step)

typedef long long LL;

void readline(char *s)
{
	scanf("%s",s);
}
void readi(int count,...)
{
	va_list ap;
	va_start(ap, count);
	for(int i=0; i<count; i++)
		scanf("%d",va_arg(ap,int*));
	va_end(ap);
}
void printi(int count,...)
{
	va_list ap;
	va_start(ap, count);
	for(int i=0; i<count; i++)
		printf("%d ",va_arg(ap,int));
	printf("\n");
	va_end(ap);
}
void printi_ln(int count,...)
{
	va_list ap;
	va_start(ap, count);
	for(int i=0; i<count; i++)
		printf("%d ",va_arg(ap,int));
	va_end(ap);
}

#define MAXN 100001
int n;
int a[MAXN];
vector<int> g[1<<13];
int r[1<<13];
int mx;
int to;
int count;
int ans[1 << 13];

int main()
{
	//freopen("1.in","r",stdin);
	
	FOR(i,0,1<<13)
	{
		g[i].push_back(0);
		r[i] = 1<<13;
	}
	scanf("%d",&n);
	FOR(i,0,n)
		scanf("%d",&a[i]);
//	FOR(i,0,n)
//		mx=max(mx,a[i]); 
	FOR(i,0,n)
	{
		for(auto iter=g[a[i]].begin(); iter!=g[a[i]].end(); iter++)
		{
			to= (*iter) ^ a[i];
			ans[to] = 1;
			while(r[to] > a[i]) // opt2
			{
				r[to] -= 1;
				if(r[to] != a[i])
					g[r[to]].push_back(to);
			}
		}
		g[a[i]].clear(); // opt1
	}
//	for(auto iter=g[mx+1].begin(); iter!=g[mx+1].end(); iter++)
//	{
//		ans[*iter]=1;
//	}
	count=0;
	ans[0]=1;
	FOR(i,0,1<<13)
		if(ans[i]==1)
			count+=1;
	printf("%d\n",count);
	FOR(i,0,1<<13)
		if(ans[i]==1)
			printf("%d ",i);
}
