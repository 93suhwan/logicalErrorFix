//////////////////////////////////////////////////////
/////                                               //
////  Credits: Rahul Verma                         ///
///  Institution: Delhi Technological University  ////
//                                               /////
//////////////////////////////////////////////////////

#include <chrono>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
// using namespace boost::multiprecision;

template <typename T> using Tree = tree<T, null_type,
    less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
// order_of_key (K): Returns the number of items that are strictly smaller than K

#define F first
#define S second
#define N 300045
#define db double
#define ld long db
#define M 1000000007
#define pb push_back
#define ll long long
#define vl vector<ll>
#define vd vector<db>
#define vld vector<ld>
#define vvl vector<vl>
// #define lll cpp_int
#define pl pair<ll,ll>
#define pd pair<db,db>
#define vpl vector<pl>
#define vpd vector<pd>
#define ull unsigned ll
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define PI 3.141592653589793238
#define all(v) v.begin(), v.end()
#define each(seq) for(auto e: seq)
#define inf numeric_limits<ll>::max()
#define F0(n, i) for(ll i = 0; i < n; i++)
#define F1(n, i) for(ll i = 1; i <= n; i++)
#define dbgpr(pr) cout << ' ' << #pr << " {" << pr.F << ',' << pr.S << "} "
#define dbgprs(seq) cout << #seq << " <"; each(seq) { dbgpr(e); } cout << ">\n"
#define dbgarr(seq) cout << #seq << " < "; each(seq) { cout << e << ' '; } cout << ">\n"
#define dbgmtx(mat) cout << #mat << " {\n"; each(mat) { cout << ' '; dbgarr(e); } cout << "}\n"
#define dbgmap(hash) cout << #hash << " { "; each(hash) { cout << e.first << ':' << e.second << ' '; } cout << "}\n"
#define dbgtree(tree) cout << #tree << " {\n"; each(tree) { cout << e.first << ": "; dbgarr(e.second); } cout << "}\n"

// Debug Template, copied from Mikel_Arteta_8 (https://codeforces.com/blog/entry/68809)
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// End of debugging template

ll sieve_size = 0, facto_size = 0;
vector<ll> F(facto_size+1);
vector<bool> state(sieve_size+1, 1);
// exp() for (N^K)%M is only valid, when N%M != 0, else return 0
ll exp(ll n,ll k,ll m=M){ll r=1,a=n%m;do{r=k&1?r*a%m:r;a=a*a%m;}while(k/=2);return r;}
ll imod(ll a,ll m=M){return exp(a,m-2,m)%m;}
ll nCr(ll n,ll r,ll m=M){return r?(F[n]*imod(F[r],m)%m*imod(F[n-r],m)%m)%m:1;}
void facto(ll n=facto_size,ll m=M){F[0]=1;F1(n,i)F[i]=(F[i-1]*i)%m;}
void sieve(ll n=sieve_size){for(ll i=4;i<=n;i+=2)state[i]=0;for(ll i=3;i<=n;i+=2)for(ll j=i*i;j<=n;j+=i)state[j]=0;}

void solve() {
 ll n, k;
 cin >> n >> k;
 vl a(n);
 F0(n, i) cin >> a[i];
 sort(all(a), greater<ll>());
 debug(a);
 ll mn = inf;
 {
  ll ans = 0, l = 0, r = n-1, kk = k;
  while(kk--) {
   ans += a[r] / a[l];
   l++; r--;
  }
  for(ll j = l; j <= r; j++) ans += a[j];
  mn = min(mn, ans);
 }
 {
  ll ans = 0, l = 0, r = n-1, kk = k;
  while(kk--) {
   ans += a[l+1] / a[l];
   l += 2;
  }
  for(ll j = l; j <= r; j++) ans += a[j];
  mn = min(mn, ans);   
 }
 cout << mn;
}

int main() {
 auto start = high_resolution_clock::now();
 ios_base::sync_with_stdio(false); // possible reason for alien segfault
 cin.tie(NULL); // possible reason for alien segfault
 ll t;
 cin >> t;
 while(t--) {
  solve();
  cout << '\n';
 }
 auto stop = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stop - start);
 cerr << "\nFinished in " << duration.count() << " µs!\n";
 return 0;
}