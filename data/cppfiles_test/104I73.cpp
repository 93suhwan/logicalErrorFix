#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define si(a)                   scanf("%d",&a)
#define sii(a,b)                scanf("%d %d",&a,&b)
#define siii(a,b,c)             scanf("%d %d %d",&a,&b,&c)
#define sl(a)                   scanf("%lld",&a)
#define sll(a,b)                scanf("%lld %lld",&a,&b)
#define slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
#define rep(i,a,b)              for(ll i = a; i<=b;  i++)
#define un(x)                   x.erase(unique(all(x)), x.end())
#define TT                      long long TC;  scanf("%lld",&TC);  for(ll tc = 1; tc<=TC; tc++)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
#define FF                      fflush(stdout);
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;




ll tot1,tot2;
ll n,m;


ll fn(ll x){
    return abs( (tot1 - x) - (tot2 - m*n + x) ) ;
}


main(){
//read;

TT{
    tot1 = 0,tot2 = 0;
    sll(n,m);

    ll ar[n],ara[n];

    ll p = 0;

    for(ll i = 0; i<n; i++){
        sll(ar[i],ara[i]);
        p = max({p,0ll,m - ara[i]});
        tot1+=ar[i];
        tot2+=ara[i];
    }

    ll l = max({p,0ll,m*n - tot2}),r = 0,ans = 1e18, sum;

    for(ll i = 0; i<n; i++){
        r+=min(ar[i],m);
    }

    for(ll i = 0; i<200; i++){
        ll m1 = l+(r-l)/3, m2 = r - (r-l)/3;
        ll p = fn(m1),q = fn(m2);
        if(p<q){
            r = m2;
            ans = min(ans,p);
            if(ans==p)  sum = m1;
        }
        else{
            l = m1;
            ans = min(ans,q);
            if(ans==q)  sum = m2;
        }
    }

    for(ll i = l; i<=r; i++){
        ans = min(ans,fn(i));
        if(ans==fn(i))  sum = i;
    }

    pii v[n];

    vector<pair<pll,int>> xx;

    for(int i = 0; i<n; i++){
        xx.pb({pll(ara[i],ar[i]),i});
    }

    sort(all(xx));

    int id = -1;

    for(ll i = 0; i<n; i++){
        pll u = xx[i].ff;
        int idx = xx[i].ss;
        if(u.ff<m && sum>0){
            id = i;
            v[idx].ss = u.ff;
            v[idx].ff = m - u.ff;
            sum-=v[idx].ff;
        }
        else break;
    }

    for(ll i = id + 1; i<n; i++){
        pll u = xx[i].ff;
        int idx = xx[i].ss;
        ll p = min( {m,sum,u.ss} );
        sum-=p;
        v[idx].ff = p;
        v[idx].ss = m - p;
    }

    for(ll i = 0; i<=id; i++){
        if(sum==0)  break;
        pll u = xx[i].ff;
        int idx = xx[i].ss;
        ll p = min( {m - v[idx].ff, u.ss - v[idx].ff, sum} );
        sum-=p;
        v[idx].ff+=p;
        v[idx].ss = m - v[idx].ff;
    }

    cout << ans << endl;

    for(int i = 0; i<n; i++){
        printf("%d %d\n",v[i].ff,v[i].ss);
    }

}






return 0;
}

