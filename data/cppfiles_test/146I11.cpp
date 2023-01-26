#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define pb push_back
#define endl '\n'
#define pii pair<ll,ll >
#define F first
#define S second
#define double long double
#define all(x) (x).begin(),(x).end()

using namespace __gnu_pbds;
using namespace std;

typedef tree<ll , null_type , less<ll> ,rb_tree_tag ,tree_order_statistics_node_update >ordered_set;

const int MOD=1e9+7 ;
const int  N=5e5+7;
const ll INF= 1e18+10;

long long po(ll x,ll y)
{
    ll ans=1;
    while(y){
        if(y&1)
        ans*=x;
        y/=2;
        x*=x;
        //ans%=MOD;
        //x%=MOD;
    }
    return ans;
}

ll n;
ll q;
int sq ;
ll a[N];
ll to[N];
ll deco[N];
ll inv_to[N];

ll get_ans(ll x,ll y)
{
    if(!y) return x;
    if(y >= sq) return get_ans(deco[x] , y-sq );
    return get_ans(to[x] , y-1);
}

ll get(ll x,ll ctr)
{
    if(!ctr) return x;
    return get(to[x] , ctr-1);
}

void upd(ll x,ll y ,ll ctr)
{
    deco[x] = y;
    if(!ctr) return;
    upd( inv_to[x] , inv_to[y] , ctr-1);
}

void solve()
{
    cin>>n>>q;
    sq = sqrt(n);
    for(ll i=1;i<=n;i++){
        ll x;
        cin>> x;
        a[i] = x;
        to[i] = x;
        inv_to[x] = i;
    }
    for(ll i=1;i<=n;i++){
        deco[i] = get(i , sq);
    }
    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x == 1){
            y = a[y] ;
            z = a[z] ;
            swap(a[y] , a[z]);
            to[inv_to[z]] = y;
            to[inv_to[y]] = z;
            swap(inv_to[y] , inv_to[z]);
            upd(inv_to[y] ,  get(inv_to[y] , sq) , sq);
            upd(inv_to[z] ,  get(inv_to[z] , sq) , sq);
            //cout<<inv_to[y]<<' '<<get(inv_to[y],sq)<<endl;
        }
        else{
            cout<<get_ans(y,z)<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);freopen(".out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--){solve();}
    return 0;
}
