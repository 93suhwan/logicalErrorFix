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
#define PI 3.14159265359
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)
#define clean fflush(stdout)

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
  
#define ordered_set tree<ii, null_type,less< ii >, rb_tree_tag,tree_order_statistics_node_update>

const ll N = 3e5 + 5;
const ll sz = 550;



struct sqrt1{
  ll a[N] , b[sz + 10];

  void pre(){
    mem(a , 0);
    mem(b , 0); 
    return;
  }

  void up(ll pos, ll val){
    ll r = N/sz;
    for(ll i = pos/sz; i <= r; i++){
      b[i] += val;
    }
    for(ll i = pos; i < N && i/sz == pos/sz; i++){
      a[i]+= val;
    }
    return;
  }
  ll prefix(ll x){
    if(x < 0) return 0;
    if(x/sz == 0) return a[x];
    return b[(x/sz)-1] + a[x];
  }
  ll query(ll a, ll b){
    return prefix(b) - prefix(a-1);
  }
}t1, c1;
struct sqrt2{
  ll a[N] , b[sz + 10];

  void pre(){
    mem(a , 0);
    mem(b , 0); 
    return;
  }
  void upd(ll i, ll x){
    a[i] += x;
    b[i/sz] += x;
    return;
  }
  void up(ll l, ll r, ll x){
    upd(l, x);
    if(r+1 < N) upd(r+1, -x);
  }
  ll prefix(ll x){
    ll ans = 0;
    ll bl = x / sz;
    for(ll i = 0; i < bl; i++) ans += b[i];
    for(ll i = bl*sz; i <= x; i++) ans += a[i];  
    return ans;
  }
  ll query(ll a){
    return prefix(a);
  }
}t2, c2;

void solve(){

   t1.pre(); c1.pre();
   t2.pre(); c2.pre();

   ll n;
   cin >> n;

   ll ans = 0;

   while(n--){
    ll x; cin >> x;
    for(ll i = 0; i < N; i += x){
      ll r = min(i + x - 1, N-1);
      ll tot = c1.query(i, r);
      ll sum = t1.query(i, r);
      ans += sum - (tot * i);
    }
    ans += c1.query(x, N - 1) * x;
    c1.up(x, 1LL);
    t1.up(x, x);
    ans += x * c2.query(x) - t2.query(x);
    for(ll i = x; i < N; i+=x){
      ll r = min(i + x, N - 1);
      c2.up(i, r, 1);
      t2.up(i, r, i);
    }
    cout << ans << ' ';
   }

   return;
}

 
int main() {
    
    
    #ifdef LOCAL
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #else 
      if(USACO){
        freopen("balancing.in", "r", stdin);
        freopen("balancing.out", "w", stdout);
      }else{
       ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
      }
    #endif
    //pre();
    ll T = 1;
   // cin >> T;
    ll CT = 0;
    while(T--){
      //  cout << "Case #" << ++CT <<": " ;
        solve();
    }
 
    return 0;
}
