#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define take(i)                    int i;cin>>i
#define taken                    take(n)
#define gcd(a,b)                __gcd(a,b)
#define endl                    '\n'
#define f                        first
#define s                        second
#define pb                        push_back
#define rep(i,a,b,c)            for(int i=a;i<b;i+=c)
#define ub                        upper_bound
#define lb                        lower_bound
#define bs                        binary_search
#define all(x)                    x.begin(), x.end()
#define mp                        make_pair
#define PI                        3.141592653589793238
#define E                        2.7182818284590452353602874713527
#define pi                        pair<int,int>
#define vi                        vector<int>
typedef unsigned long int    uli;
typedef long long        ll;
typedef unsigned long long    ull;
const unsigned int M = 1000000007;

using namespace std;

ull binpow(ll a,ll b,ll m);

void solve(){
    ll n,k;
    cin>>n>>k;
    k++;
    int arr[n];
    ll ans=0;
    rep(i,0,n,1)cin>>arr[i];
    rep(i,0,n,1){
        ll k1=binpow(10,arr[i],M);
        if(i==n-1){
            // cout<<k<<" ";
        }
        else{
            int diff=arr[i+1]-arr[i];
            ll j=9;
            while(diff--){
                j=min(k,j);
                k-=j;
                ans+=j*k1;
                j=j*10;
            }
        }
    }
    if(k)cout<<k;
    cout<<ans;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    return 0;
}

ull binpow(ll a,ll b,ll m){
    if(b==0)return ll(1);
    ull a1=binpow(a,b/2,m);
    if(b%2) {
        a1 = (a1*a1)%m;
        return (a*a1)%m;
    }
    else return (a1*a1)%m;
}