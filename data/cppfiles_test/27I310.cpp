#include <bits/stdc++.h>


// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

using namespace std;

//order_of_key (k) -> Number of items less than k 
//find_by_order(k) -> index of Kth element
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

template<typename T> using indexed_set = 
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using indexed_multiset = 
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using indexed_multiset_greater = 
    tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename Key, typename T> using indexed_map =
    tree<Key, T, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

#define boost ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i, x, y) for (ll i = x; i < y; ++i)
#define repr(i, x, y) for (ll i = x; i >= y; --i)
#define all(lst) lst.begin(), lst.end()
#define rall(lst) lst.rbegin(), lst.rend()
#define ceil(a, b) ((a + b - 1) / (b))
#define sum(lst) accumulate(all(lst), 0ll)

#define fix(n)   fixed<<setprecision(n)

#define countval(lst, val) count(all(lst), val)
#define lcn(lst, val) find(all(lst), val) - lst.begin()
#define sortlst(lst) sort(all(lst))
#define sorted(lst) is_sorted(all(lst))
#define rsortlst(lst) sort(rall(lst))
#define setbits(n) __builtin_popcount(n)
#define sortarr(x, n) sort(x, x + n)
#define sz(lst) (ll)lst.size()
#define lcn(lst, val) find(all(lst), val) - lst.begin()

#define ub(x,y) upper_bound(all(x),y)
#define lb(x,y) lower_bound(all(x),y)

template<class T> using pques =  priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqueg =  priority_queue<T>;
template<class T> using vec = vector<T>;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<int> vi;

typedef vector<string> vs;
typedef vector<bool> vb;


void input() {return;}
template<typename T1, typename... T2>
    void input(T1 & x, T2&... args){((cin >> x), input(args...));}
void wrt() { cout << "\n"; return;}
template<typename T1, typename... T2>
    void wrt(T1 x, T2... args){((cout << x << ' '), wrt(args...));}
template<typename T> void inputlst(T & lst, int x, int y)
    { for(int i = x ; i < y; i++ ) cin >> lst[i]; }
template<typename T> void printlst(T & lst, int x, int y)
    { for(int i = x ; i < y; i++ ) cout << lst[i] << ' '; wrt(); }

template <class T>
istream& operator>>(istream& is, vector<T>& v) {for (T& x : v)  is >> x;return is;}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    if (!v.empty()) {os << v.front();for (int i = 1; i < v.size(); ++i)os << ' ' << v[i];}return os;}

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

template<class T>
void erase(multiset<T> &t , T val){ auto it = t.find(val);assert(it != t.end());t.erase(it);}
template<class T>
void erase(set<T> &t , T val){ auto it = t.find(val);assert(it != t.end());t.erase(it);}


//---------------------------------------DEBUGGING PROCESS----------------------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print() {cerr << "\n"; return;}
template<typename T1, typename... T2>
void _print(T1 t, T2... args) {((cerr << t<<' '),_print(args...));}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//---------------------------------------CONST FUNCT ----------------------------------------
const ll  MOD = 1e9+7;
vl _range(ll x,ll y,ll z=1){vl v;for(int i=x;i<=y;i+=z)v.pb(i);return v;}
ll _lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll _sum(vi a){ return accumulate(all(a), 0ll); }
ll _add(ll x, ll y) { x %= MOD, y %= MOD; return (x + y) % MOD; }
ll _sub(ll x, ll y) { x %= MOD, y %= MOD; return (x - y + MOD) % MOD; }
ll _mul(ll x, ll y) { x %= MOD, y %= MOD; return (x * 1ll * y) % MOD; }
ll _pow(ll x, ll y) { if (y == 0) return 1; else if (y % 2 == 0){ 
ll _tmp=_pow(x, y / 2); return _mul(_tmp, _tmp); } else return _mul(x, _pow(x, y - 1)); }
ll _inv(ll p) { return _pow(p, MOD - 2); }
ll _div(ll x, ll y) { x %= MOD, y %= MOD; return _mul(x, _inv(y)); }
ll _nCr(ll n, ll r, vl & fact) { return _mul(fact[n], _inv(_mul(fact[r], fact[n - r]))); }
// ############################# CODE IS HERE ##############################

const ll N = 5e5+5;

ll testCase=1;
ll n,x,k;
vl fact(N,0);
// void f(){
//     fact[0]=1;
//     rep(i,1,N+1){
//         fact[i] = _mul(fact[i-1],i);
//     }
// }

void solve(){
    // ll n;cin>>n;
    // ll ans = _mul(fact[n],_nCr((2*n),n+1,fact));
    // cout<<ans<<endl;
    int n,m,d;cin>>n>>m>>d;
    d = d-2;
    if(d<0){
        return wrt("NO");
    }else{
        n = n-(d+1);
        m = m - d;
        ll x = n * (n-1)/2;
        m = m  - (x);
        // if(d==1){
            m -= 2*n;
            if(m==0){
                wrt("YES");
            }else{
                wrt("NO");
            }
        // }else{
            
        // }
    }
}

signed main(){
  boost;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  ll t=1;
  // f();
  cin>>t;
  while(t--){
    // cout<<"Case #"<<testCase++<<": ";
    solve();
  }
  return 0;
}