#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri int
#define ll __int128_t
#define ui unsigned int
const int MOD=1e9+7;
il ll read(){
    bool f=true;ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=false;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    if(f) return x;
    return ~(--x);
}
il void write(const ll &x){if(x>9) write(x/10);putchar(x%10+'0');}
il void print(const ll &x) {x<0?putchar('-'),write(~(x-1)):write(x);putchar('\n');}
il ll max(const ll &a,const ll &b){return a>b?a:b;}
il ll min(const ll &a,const ll &b){return a<b?a:b;}
const int MAXN=2e5+7;
int n,q;
ll s1[MAXN],s2[MAXN];
struct segT
{
    int cnt;
    struct T
    {
        ll tag,mn;
    }t[MAXN<<2];
    #define lc u<<1
    #define rc u<<1|1
    #define mid (L+R>>1)
    void update(int u){
        t[u].mn=min(t[lc].mn,t[rc].mn);
    }
    void pushr(int u,ll w){
        t[u].tag+=w,t[u].mn+=w;
    }
    void pushdown(int u){
        if(t[u].tag){
            pushr(lc,t[u].tag),pushr(rc,t[u].tag);
            t[u].tag=0;
        }
    }
    void modify(int u,int l,int r,ll w,int L=1,int R=n){
        if(l==L&&r==R) return pushr(u,w);
        pushdown(u);
        if(r<=mid) modify(lc,l,r,w,L,mid);
        else if(l>mid) modify(rc,l,r,w,mid+1,R);
        else modify(lc,l,mid,w,L,mid),modify(rc,mid+1,r,w,mid+1,R);
        update(u);
    }
    ll querymn(int u,int l,int r,int L=1,int R=n){
        if(l==L&&r==R) return t[u].mn;
        pushdown(u);
        if(r<=mid) return querymn(lc,l,r,L,mid);
        else if(l>mid) return querymn(rc,l,r,mid+1,R);
        else return min(querymn(lc,l,mid,L,mid),querymn(rc,mid+1,r,mid+1,R));
    }
}T;
int main(){
    n=read(),q=read();
    for(ri i=1;i<=n;++i){
        ll x=read();
        T.modify(1,i,i,x);
        s1[i]=s1[i-1]+x;
        s2[i]=s2[i-1]+x*x;
    }
    for(ri i=1;i<=q;++i){
        ll l=read(),r=read(),d=read(),mi;
        ll sz=(r-l+1);
        mi=T.querymn(1,l,r);
        if(sz==1){
            puts("Yes");
            continue;
        }
        ll sum1=s1[r]-s1[l-1],sum2=s2[r]-s2[l-1];
        ll tmp1=(mi+mi+(sz-1)*d)*sz/2;
        ll tmp=sz*mi*mi+(sz-1)*sz*(2*sz-1)/6*d*d+mi*d*sz*(sz-1);
        // printf("%lld %lld\n",sum1,sum2);
        if(tmp%MOD!=sum2%MOD||tmp1%MOD!=sum1%MOD){
            d=MOD-d;
            sum1=s1[r]-s1[l-1],sum2=s2[r]-s2[l-1];
            tmp1=(mi+mi+(sz-1)*d)*sz/2;
            tmp=sz*mi*mi+(sz-1)*sz*(2*sz-1)/6*d*d+mi*d*sz*(sz-1);
            if(tmp%MOD!=sum2%MOD||tmp1%MOD!=sum1%MOD) puts("No");
            else puts("Yes");   
        }
        else puts("Yes");
    }
}
/*
9 1
17 0 12 6 10 8 2 4 5
2 3 6
2 4 6
4 6 2
2 8 2
1 2 17
1 8 2
9 9 14

*/