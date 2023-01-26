#include<bits/stdc++.h>
#define ll int64_t
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key
ll MOD=1e9+7 ;
ll MAXN=1e5;
ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll add(ll x,ll y){return mod(mod(x)+mod(y));}
ll mul(ll x,ll y){return mod(mod(x)*mod(y));}
ll binpow(ll a, ll b) {a %= MOD;ll res = 1;while (b > 0) {
if (b & 1)res = res * a % MOD;a = a * a % MOD;b >>= 1;}return res;}
ll fact(ll n){ll num=1;for(ll i=1;i<=n;i++){num=mul(num,i);mod(num);}return num;}
ll ncr(ll n,ll r){ll fn=fact(n);ll rn=mod(fact(r)*fact(n-r));return mod(fn*binpow(rn,MOD-2));}

/*------------------------------------------------------------------------------------------------*/

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    set<pair<int,int>>us;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*'){
                if(not us.empty()&&us.count({i,j}))
                    continue;
                if(j-1>0 && j+1<m && i-1>0){
                    if(us.count({i-1,j+1})&&us.count({i-1,j-1})){
                        us.insert({i,j}); continue;
                    }
                }
                int x=j+2*k;
                for(;x<m;x+=2){
                    if(s[i][x]=='*'){
                        break;
                    }
                }
                if(x>m){
                    x=j-2*k;
                    for(;x>0;x-=2){
                        if(s[i][x]=='*'){
                            break;
                        }
                    }
                }
                if(x<0){
                    cout<<"No\n";
                    return;
                }
                int le,re;
                if(x>j)
                    le=j,re=x;
                else le=x,re=j;
                int flag=1;
                for(int r=i;r<n;r++){
                    if(le==re){
                        if(s[r][le]=='*')
                            us.insert({r,le});
                        else{
                            cout<<"No\n"; return;
                        }flag=0;
                        break;
                    }
                    if(s[r][le]=='*' && s[r][re]=='*'){
                        us.insert({r,le});
                        us.insert({r,re});
                        le++,re--;
                    }else{
                        cout<<"No\n"; return;
                    }
                }
                if(flag){
                    cout<<"No\n"; return;
                }
            }
        }
    }
    cout<<"Yes\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}