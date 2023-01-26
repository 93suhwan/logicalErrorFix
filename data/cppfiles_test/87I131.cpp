
// submitted by saketh kumar pabba

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long int
#define pb push_back
#define ordered_multiset tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define fr(i,x,n) for(int i=x;i<n;i++)
#define frr(i,x,n) for(int i=n-1;i>=x;i--)
#define take(v,n) cin>>n; std::vector<ll> v(n); for(auto &i: v) cin>>i;
#define out(v,n) for(auto i: v) cout<<i<<" "; cout<<"\n";

ll mod = 998244353;

// modular inverse 
ll inv(ll p,ll q){
    ll expo;
    expo = mod - 2;
    while (expo) {
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        expo >>= 1;
    }
    return p;
}

// modular exponentiation
ll power(ll x, ll y){
    ll res = 1;
    while(y>0){
        if(y&1){
            res = (res*x)%mod;
        }
        y>>=1;
        x = (x*x)%mod;
    }
    return res;
}
int main() 
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        map<ll,ll> mp;
        vector<ll> v(m);
        for(auto &i: v) cin>>i;
        for(auto i: v){
            mp[i]++;
        }
        ll st=0;
        // vector<pair<ll,ll>> p;
        for(auto i: mp){
            // p.push_back({i.first,st+i.second});
            mp[i.first] = st+i.second-1;
            st = st+i.second;
        }
        // for(auto i: mp){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        vector<ll> seats(m,0);
        ll inc = 0;
        for(int i=0;i<m;i++){
            ll pos = mp[v[i]];
            for(int j=0;j<pos;j++){
                if(seats[j]!=0) inc++;
            }
            seats[pos]=v[i];
        }
        cout<<inc<<"\n";
    }
    return 0;
}