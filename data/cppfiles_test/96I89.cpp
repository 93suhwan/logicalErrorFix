#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
#define ll long long
#define ull unsigned long long
#define N 1000005
#define mod 998244353
const ull inf = 1e19;
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

int n,x;
ll C[505][505],Ans,f[505][505];

ll fast(ll x,ll y)
{
   if(x==0) return 1;
   ll base=x; x=1;
   while(y)
   {
      if(y&1) (x*=base)%=mod;
      (base*=base)%=mod;
      y>>=1;
   }
   return x;
}

int main()
{  
   n=read();x=read();
   C[0][0]=1;
   for(int i=1;i<=n;i++)
   {
      C[i][0]=1;
      for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
   }
   if(n==2) {printf("%d\n",x);return 0;}
   for(int i=2;i<=n;i++)
   {
      for(int j=1;j<=x;j++)
      {
         if(i==2) {f[i][j]=j;continue;}
         if(j<i) {f[i][j]=fast(j,i);continue;}
         for(int k=0;k<=i-2;k++)
         {
            (f[i][j]+=f[i-k][j-i+1]*fast(i-1,k)%mod*C[n][k]%mod)%=mod;
         }
         f[i][j]+=fast(i-1,i);
         //cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
      }
   }
   cout<<f[n][x];
   return 0;
}             
/*


*/