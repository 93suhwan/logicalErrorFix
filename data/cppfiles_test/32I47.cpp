#include<bits\stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef pair<double,double> pdd;
typedef complex<double> comp;
const int N=1e5+5;
const int M=sqrt(N)+1;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const double eps=1e-13;
const double pi=acos(-1.0);
#define ls (i<<1)
#define rs (i<<1|1)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mem(a,b) memset(a,b,sizeof(a))
LL read()
{
    LL x=0,t=1;
    char ch;
    while((ch=getchar())<'0'||ch>'9') if(ch=='-') t=-1;
    while(ch>='0'&&ch<='9'){ x=(x<<3)+(x<<1)+ch-'0'; ch=getchar(); }
    return x*t;
}
LL a[N],f[N][M],g[N][M];
LL s[N];
int main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        int m=sqrt(n)+1;
        for(int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j]=-inf;
        for(int i=1;i<=n;i++) f[i][1]=a[i];
        for(int i=n-1;i;i--) f[i][1]=max(f[i+1][1],a[i]);

        int ans=1;
        for(int j=2;j<=m;j++)
        {
            for(int i=n;i>=j;i--)
            {
                int k=i+j-1;
                if(k>n) continue;
                if(s[i]-s[i-j]<f[k][j-1]) f[i][j]=s[i]-s[i-j];
                //printf("%d %d %d %lld %lld\n",j,i,k,s[i]-s[i-j],f[k][j-1]);
            }
            for(int i=n-1;i;i--) f[i][j]=max(f[i][j],f[i+1][j]);
            if(f[1][j]!=-inf) ans=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
3
2
5 5
5
5 -2 10 -9 4
7
-1 -2 3 4 5 6 7
*/
