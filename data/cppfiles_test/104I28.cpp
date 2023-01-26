#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N];
void solve()
{
    int n=read(),m=read();
    ll s=0;
    for(int i=1;i<=n;++i)
    {
        s+=a[i]=read();
        s-=b[i]=read();
    }
    for(int i=1;i<=n;++i)
    {
        ll l=m+s,r=m-s;
        if(l&1)++l,--r;
        l>>=1,r>>=1;
        ll t=min(min(max(max(0,-l),r-b[i]),r),a[i]-l);
        s-=a[i]=l+t;
        s+=b[i]=r-t;
    }
    write(abs(s),'\n');
    for(int i=1;i<=n;++i)printf("%d %d\n",a[i],b[i]);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}
