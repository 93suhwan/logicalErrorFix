#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
#define ll long long
#define ull unsigned long long
#define N 1000005
#define M 8193
#define mod 1000000007
const ll inf = 1e17;
const int INF = 1e9+10;
const double eps = 1e-6;
inline ll read()
{
   ll f=0,g=1;
   char ch=getchar();
   while(ch<'0'||ch>'9') {if(ch=='-') g=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') {f=(f<<1)+(f<<3)+(ch^48);ch=getchar();}
   return f*g;
}
void Write(ll x)
{
   if(x<0) x=~x+1,putchar('-');
   if(x>9) Write(x/10);
   putchar(x%10+'0');
}


int n,num,mx;
vector<int>g[N];
int a[N],r[N];
bool Ans[N];

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]);
	for(int i=0;i<=mx;i++) g[i].push_back(0),r[i]=M;
	Ans[0]=1;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=0;j<(int)g[x].size();j++)
		{
			int Val=x^g[x][j];
			Ans[Val]=1;
			while(r[Val]>x)
			{
				r[Val]--;
				if(r[Val]!=x) g[r[Val]].push_back(Val);
			}
		}
		g[x]={};
	}
	for(int i=0;i<M;i++) num+=Ans[i];
	printf("%d\n",num);
	for(int i=0;i<M;i++) if(Ans[i]) printf("%d ",i);
   	return 0;
} 
             
/*
4
aaaa

*/