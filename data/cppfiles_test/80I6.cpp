#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define SZ(x) (int)(x.size())
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn = 4e6 + 6;
const int  inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 2e3 + 3;
ll qpow(ll x,ll y) { ll ans=1;x%=mod;  while(y) { if(y&1) ans=ans*x%mod; x=x*x%mod;  y>>=1; } return ans; }
//
int _;


int n,m,k;
int a[maxn],b[maxn],c[maxn];
int d[maxn];
int cntb[maxn];
void upd(int x,int v) {
   for(;x<=k;x+=x&(-x)) d[x]+=v; 
}
int ask(int x) {
    int ans=0;
    for(;x>0;x-=x&(-x)) ans+=d[x];
    return ans;
}
vector<int>v[maxn];

#define ls rt<<1
#define rs rt<<1|1
#define mid (l+r>>1)

struct Node {
    int sm,ms;
}t[maxn*2];

void pu(int rt) {
    t[rt].sm=t[ls].sm+t[rs].sm;
    t[rt].ms=min({0,t[ls].ms,t[ls].sm+t[rs].ms});
}
void build(int rt,int l,int r) {
    t[rt].sm=1;t[rt].ms=0;
    if(l==r) {
        return ;
    } else {
        build(ls,l,mid);
        build(rs,mid+1,r);
        pu(rt);
    }
}
void change(int rt,int l,int r,int p,int v) {
    if(l==r) {
        t[rt].sm=v;t[rt].ms=min(v,0);
    }
    else {
        if(p<=mid) change(ls,l,mid,p,v);
        else change(rs,mid+1,r,p,v);
        pu(rt);
    }
}

#undef ls
#undef rs
#undef mid
void so() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=a[i];
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),c[i+n]=b[i];
    sort(c+1,c+1+m+n);
    k=unique(c+1,c+1+n+m)-c-1;
    for(int i=1;i<=k;i++) d[i]=cntb[i]=0,v[i].clear();
    ll ans=0;
    for(int i=1;i<=n;i++) {
        a[i]=lower_bound(c+1,c+1+k,a[i])-c;
        upd(a[i],1);
        ans+=i-ask(a[i]);
        v[a[i]].pb(i);
    }
    for(int i=1;i<=m;i++) {
        b[i]=lower_bound(c+1,c+1+k,b[i])-c;
        cntb[b[i]]++;
    }
    build(1,1,k);
    int les=0;
    for(int i=1;i<=k;i++) {
        for(auto j:v[i]) change(1,1,k,j,0);
        ans+=1ll*cntb[i]*(les+t[1].ms);
        les+=SZ(v[i]);
        for(auto j:v[i]) change(1,1,k,j,-1);
    }
    printf("%lld\n",ans);
}
void init() {


}  
int main() {
    init();
    for(scanf("%d",&_);_;_--) { 
        so();
    }
    return 0;
}