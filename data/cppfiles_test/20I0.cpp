/***Farhan132***/
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
 
 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<ll> vll;
typedef pair<ll , ll> ii;
typedef vector< ii > vii;
typedef pair < pair < ll , ll > , pair < ll , ll > > cm; 
 
#define ff first
#define ss second
#define pb push_back
#define in insert
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(b) for(int i=1;i<=(b);i++)
#define f11(b) for(int j=1;j<=(b);j++)
#define f2(a,b) for(int i=(a);i<=(b);i++)
#define f22(a,b) for(int j=(a);j<=(b);j++)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld", &a , &b)
#define pf(a) printf("%lld\n",a)
#define pff(a,b) printf("%lld %lld\n", a , b)
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)
#define clean fflush(stdout)
 
const ll mod =  (ll) 998244353;
//const ll mod =  (ll) 1e9 + 7;
const ll maxn = (ll)2e5 + 5;
const int nnn = 1048590;
const int inf = numeric_limits<int>::max()-1;
//const ll INF = numeric_limits<ll>::max()-1;
//const ll INF = (ll)1e18;
 
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};
 
bool USACO = 0;
 
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<ii, null_type,less< ii >, rb_tree_tag,tree_order_statistics_node_update>

const ll N = 405;

ll sum[N][N];
ll a[N][N];
ll gt[N];

void solve(){
   
   ll n , m;
   cin >> n >> m;

   for(ll i = 1; i <= n; i++){
    sum[i][0] = 0;
    for(ll j = 1; j <= m; j++){
      char c; cin >> c;
      a[i][j] = (c == '1');
      sum[i][j] = sum[i][j-1] + a[i][j];
    } 
    sum[i][m + 1] = sum[i][m];
   }
   ll ans = 1e18;
   for(ll x = 1; x <= m; x++){
    for(ll y = x + 3; y <= m; y++){
      for(ll i = 1; i <= n; i++) gt[i] = 1e18;
      for(ll i = n; i >= 1; i--){
        ll sz = y - x-1;
        ll val = sz - (sum[i][y-1] - sum[i][x]);
        ans = min(ans , val + gt[i]);
        gt[i] = gt[i] + 2 - (a[i][x] + a[i][y]) + (sum[i][y-1] - sum[i][x]);
        
        if(i >= 5){
          ll res = val;
          for(ll j = i-3; j <= i-1; j++){
            res += 2 - (a[j][x] + a[j][y] ) + (sum[j][y-1] - sum[j][x]);

          }
          gt[i - 4] = min(gt[i - 4] , res);
        }
      }
    }
   }
   cout << ans << '\n';
   

   return;
}

 
int main() {
    
    
    #ifdef LOCAL
        freopen("in", "r", stdin);
        freopen("out.txt", "w", stdout);
    #else 
       ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    #endif
    //pre();
   // mem(T.ft , 0);
    ll T = 1;
    cin >> T;
    ll CT = 0;
    while(T--){
       //cout << "Case #" << ++CT <<": " ;
        solve();
    }
 
    return 0;
}