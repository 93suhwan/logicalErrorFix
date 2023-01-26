#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
#define ll long long
#define ull unsigned long long
#define N 1000005
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

int n,siz;
ll Sum[N];
ll f[505][505];


int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+read();
		memset(f,0,sizeof f);
		f[n+1][0]=inf;
		siz=0;
		while(siz*(siz+1)/2<=n)siz++;
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=siz;j++)
			{
				f[i][j]=f[i+1][j];
				if(i+j-1<=n&&Sum[i+j-1]-Sum[i-1]<f[i+j][j-1]) f[i][j]=max(f[i][j],Sum[i+j-1]-Sum[i-1]);
			}
		}
		int Ans=0;
		for(int i=siz;i>=0;i--) if(f[1][i]>0) {Ans=i;break;}
		Write(Ans);putchar('\n'); 
	}
   	return 0;
} 
             
/*
4
aaaa

*/