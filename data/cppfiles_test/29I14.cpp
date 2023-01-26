/*input
3
3 2 1

*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<ll,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
const int maxn=3e5+5;
const ll maxlg=__lg(maxn)+2;
struct bit{
    ll bit[maxn];
    void upd(int p,int x){
        while(p<maxn){
            bit[p]+=x;
            p+=lowb(p);
        }
    }
    ll query(int p){
        ll ans=0;
        while(p){
            ans+=bit[p];
            p-=lowb(p);
        }
        return ans;
    }
}bs,bt;
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    ll ans=0,pref=0;
    REP(i,n){
        int x;
        cin>>x;
        ans+=x*i+bs.query(x)+pref;
        pref+=x;
        for(int j=x;j<maxn;j+=x){
            int r=min(maxn-1,j+x-1);
            ans-=(bt.query(r)-bt.query(j-1))*j;
            bs.upd(j,-x);
        }
        bt.upd(x,1);
        cout<<ans<<' ';
    } 
}
