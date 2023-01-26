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
 
//const ll mod =  (ll) 998244353;
const ll mod =  (ll) 1e9 + 7;
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
 
#define ordered_set tree<ll, null_type,less< ll >, rb_tree_tag,tree_order_statistics_node_update>

const ll N = 105;

ll dp[N][N];
ll cnt[N][N];
ll mx[N];

ll fac[N];
 
void pre(ll n){
  fac[0] = 1;
  for(ll i = 1; i < n; i++){
    fac[i] = (fac[i-1] * i)%mod;
  }
  return;
}
ll pw(ll a , ll b){
  ll res = 1;
  while(b){
    if(b&1) res = (res*a)%mod;
    a = (a*a)%mod;
    b /= 2;
  }
  return res;
}
 
ll nCr(ll n , ll r){
  if(n == r) return 1;
  if(n < r) return 0;
  ll ans = fac[n] * (pw(fac[r] , mod-2));
  ans %= mod;
  ans *= pw(fac[n-r] , mod-2);
  return ans%mod;
}

vector < ll > v[N];

void dfs(ll s, ll p, ll id, ll d){
  mx[id] = max(mx[id] , d);
  cnt[id][d]++;
  for(auto u : v[s]){
    if(u - p) dfs(u , s , id , d + 1);
  }
  return;
}

bool comp(ll a, ll b){
  return mx[a] > mx[b];
}

ll calc(vector < ll > a , ll k){
  if(a.size() == 0) return 0;
  if(a.size() < k) return 0;
  a.emplace(a.begin() , 0);
  ll n = a.size() - 1;
  for(ll i = 0; i <= n; i++){
    for(ll j = 0; j <= k; j++) dp[i][j] = 0;
  }
  dp[0][0] = 1;
  for(ll i = 1; i <= n; i++){
    for(ll j = 0; j <= k; j++){
      dp[i][j] = dp[i - 1][j];
      if(j) dp[i][j] = (dp[i][j] + a[i] * dp[i-1][j-1])%mod;
    }
  }
  return dp[n][k];
}

void solve(){

    ll n , k;
    cin >> n >> k;

    for(ll i = 1; i <= n; i++){
      v[i].clear();
    }
    for(ll i = 1 ; i < n; i++){
      ll x , y;
      cin >> x >> y;
      v[x].pb(y);
      v[y].pb(x);
    }
    if(k == 2){
      cout << (n * (n-1))/2 << '\n';
      return;
    }
    ll ans = 0;
    for(ll root = 1; root <= n; root++){
      vector < ll > idx;
      for(auto u : v[root]){
        idx.pb(u);
        mx[u] = 0;
        for(ll j = 0; j <= n; j++) cnt[u][j] = 0;
        dfs(u , root , u , 1);
      }
      sort(idx.begin() , idx.end());
      for(ll d = 1; d <= n; d++){
        vector < ll > tmp;
        for(auto u : idx){
          if(mx[u] < d) break;
          tmp.pb(cnt[u][d]);
        }
        ans = (ans + calc(tmp , k))%mod;
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
    pre(N);
    ll T = 1;
    cin >> T;
    ll CT = 0;
    while(T--){
      // cout << "Case #" << ++CT <<": " ;
        solve();
    }
 
    return 0;
}