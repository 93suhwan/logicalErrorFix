#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mst(a,b) memset(a,b,sizeof(a))
#define rush() int TT;cin>>TT;for(int TTT=1;TTT<=TT;++TTT)
#define forr(i,x,y) for(int i=x;i<y;++i)
#define forrr(i,x,y) for(int i=x;i<=y;++i)
#define roff(i,x,y) for(int i=x;i>y;--i)
#define rofff(i,x,y) for(int i=x;i>=y;--i)
#define lowbit(x) (x&-x)
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define sf scanf
#define pf printf
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
void in() {}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr) {
    cin>>t;
    in(otr...);
}
void out(int a,bool ln) {
    printf("%d%c",a," \n"[ln]);
}
void out(ll a,bool ln) {
    printf("%lld%c",a," \n"[ln]);
}
void out(db a,int digit,bool ln) {
    printf("%.*f%c",digit,a," \n"[ln]);
}
const int maxn=5e5+5;
const int maxm=2e6+5;
const int inf=0x3f3f3f3f;
const db eps=1e-7;
const ll mod=998244353;
int a[maxn], n;
map<ll, int> m;
vector<int> v, dep;
vector<bool> isleaf;
vector<vector<int>> edge;

inline bool add(int u, bool f = false) {
    if(m.count(u))
        return false;
    m[u] = v.size();
    isleaf.eb(f);
    edge.eb();
    dep.eb(0);
    v.eb(u);
    return true;
}

void init(ll u) {
    if(!add(u, true))
        return;
    ll tmp = 1;
    while(tmp < u) tmp<<=1;
    while(u) {
        bool flag = add(tmp - u);
        edge[m[tmp - u]].eb(m[u]);
        edge[m[u]].eb(m[tmp - u]);
        if(!flag)
            return;
        u = tmp - u;
        while(tmp&&(tmp>>1)>=u)
            tmp>>=1;
    }
}

pii dfs(int u, int f, int d) {
    pii ret = {-1, -1};
    if(isleaf[u])
        ret = {d, u};
    for(auto& v : edge[u]) {
        if(v == f)
            continue;
        pii tmp = dfs(v, u, d+1);
        if(tmp.fi>ret.fi) {
            ret = tmp;
        }
    }
    return ret;
}


int main() {
    in(n);
    forrr(i,1,n) {
        in(a[i]);
    }
    forrr(i,1,n) {
        init(a[i]);
    }
    /*for(auto& u : v) {
        out(u, 0);
    }
    pf("\n");*/
    ll ans = 0, x, y;
    x = dfs(m[0], -1, 0).se;
    tie(ans, y) = dfs(x, -1, 0);
    forrr(i,1,n) {
        if(a[i]==v[x])
            out(i, 0);
        if(a[i]==v[y])
            out(i, 0);
    }
    out(ans, 1);
}
