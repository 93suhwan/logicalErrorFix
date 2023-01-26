#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define mp make_pair
// #define endl "\n"
#define forn(i,n) for(ll i = 0 ; i < int(n); ++i)
#define forr(i,n) for(ll i = int(n)-1 ; i>=0 ; i--)
#define FOR(i,a,b) for(ll i=int(a) ; i<=int(b) ; ++i)
#define sz(z) (ll)z.size()
#define lb lower_bound
#define ub upper_bound
#define dbg cout << "yo" << endl
#define N (ll)2e6+10
#define M (ll)1e6+10
 
const ll mod = 998244353 ;
const ll inf = 1e18 ;



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        ll n ;cin >> n ;
        ll a[n] , b[n] , m[n] , x[n] ;
        
        
        map<ll, set<ll> > mask ;
        for(int i=0 ; i<n; i++){
             cin >> a[i] >> b[i] >> m[i] ;
             mask[a[i]+b[i]-m[i]].insert(i);
        }

        ll ans = 0 ;

        for(auto e:mask){
            set<ll> s = e.S ;
            ll mx = 0 ;
            for(auto idx:s){
                mx = max(mx , a[idx]-m[idx]) ;
            }

            bool ok = 1 ;

            for(auto idx:s){
                if(mx>a[idx])ok=0 ;
            }

            if(ok){
                ans++ ;
                for(auto idx:s){
                    x[idx]=mx ;
                }
            }else {
                ans+=2 ;
                for(auto idx:s){
                    if(mx>a[idx])x[idx]=0 ;
                    else x[idx]=mx ;
                }

            }

        }


        cout << ans << endl ;

        for(int i=0 ; i<n ; i++){
            ll ca = a[i]-x[i] ;
            cout << ca << " " << m[i]-ca << endl;
        }
    }



   return 0 ;
}