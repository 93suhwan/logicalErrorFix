#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef long long int ll;
// using namespace __gnu_pbds;
 
// typedef tree<int, null_type, less<ll>, rb_tree_tag,
//                     tree_order_statistics_node_update>
//                     ordered_set;
 
#define ull                 unsigned long long
#define fast                ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define rep(i, m, n)        for (auto i = m; i < n; i++)
#define fo(m)               for(auto it: m)
#define ppi                 pair<int, int>
#define ppl                 pair<ll, ll>
#define pb                  push_back
#define endl                "\n"
#define all(v)              (v).begin(), (v).end()
#define ii                  <int, int>
#define lii                 <ll, ll>
#define f                   first
#define ss                  second
#define in                  insert
#define lb                  lower_bound
#define ub                  upper_bound
#define sz                  size()
#define bg                  begin()
#define pq                  priority_queue
#define vc                  vector<int>
#define vcp                 vector<ppi>
#define vcl                 vector<ll>
#define mp                  map<int, int> 
#define mpl                 map<ll, ll>
#define mem1(a)             memset(a, -1 ,sizeof(a))
#define mem0(a)             memset(a, 0 ,sizeof(a))
#define memf(a)             memset(a, false ,sizeof(a))
#define memt(a)             memset(a, true ,sizeof(a))
#define sd                  greater<int>()
#define sdp                  greater<ppi>()
#define enl                 "\n"; return
#define SET(n)              cout << fixed << setprecision(n)
#define pi                  3.14159265
#define ppc                 __builtin_popcount
#define ppcll               __builtin_popcountll
#define qr(l)               cout<<"? "<<l<<endl; cout.flush();
#define qr2(l, r)           cout<<"? "<<l<<" "<<r<<endl; cout.flush();
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
template<typename T> istream& operator>>(istream& is,  vector<T>  &v){ for(auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
 
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second; return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second << endl; return os;} 

template<class T> void _print(T n){cerr<<n;}
template<class T, class V> void _print(T a[], V n){cerr<<"Array: [ "; rep(i, 0, n){_print(a[i]); cerr<<" ";} cerr<<" ] \n";}
template<class T, class V> void _print(pair<T, T> a[], V n){cerr<<"Pair Array: [ "; rep(i, 0, n){cerr<<"{";_print(a[i].f); cerr<<", "; _print(a[i].ss); cerr<<"},";cerr<<" ";} cerr<<"] \n";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
struct pp{int x; char y; int z;};
const int MOD= 1e9+7, inf=INT_MAX, inff=INT_MIN, linf=LONG_MAX;
const int N=1000000+1;
ll expo1(ll a, ll b)  {ll res = 1; while (b > 0) {    if (b & 1)res = (res * a);     a = (a * a);     b = b >> 1;} return res;}
ll expo(ll a, ll b)   {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % MOD; a = (a * a) % MOD; b = b >> 1;} return res;}
int LOG(ll n, ll x) {int ans=-1;while(n){    ans++, n/=x;}return ans;}


void Solve()
{ 
  ll n, k, x; cin>>n>>k>>x;
  string s; cin>>s;
  ll c=0;
  vcl v;
  rep(i, 0, s.sz)
  {
    if(s[i]=='*') c++;
    else
    {
      if(c) v.pb(k*c+1);
      c=0;
    }
  }
  if(c) v.pb(k*c+1);

  reverse(all(v));

  ll t=1;

  ll I=-1;
  rep(i, 0, v.sz)
  {
    t*=v[i];
    if(t>=x)
    {
      I=i;
      break;
    }
  }
  ll prev, rem=x;
  vc ans;
  for(int i=I; i>=0; i--)
  {
    prev=t/v[i];

    ll q=0;
    if(rem>0 && prev>0)
      q=(rem-1)/prev;
    ans.pb(q);
    rem-=prev*q;
    t/=v[i];
  }
  reverse(all(ans));
  string final="";
  ll g=0;
  for(ll i=(int)s.sz-1; i>=0; i--)
  {
    if(s[i]=='a')
      final.pb('a');
    else if(g<ans.sz && (!(i+1<s.sz && s[i+1]=='*')))
    {
      rep(i, 0, ans[g])
      {
        final.pb('b');
      }
      g++;
    }
  }
  reverse(all(final));
  cout<<final<<endl;



}


int main()
{ 
    fast
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    int T=1;

    // SieveOfEratosthenes();
    
    cin >> T;
    while (T--)
    {
        Solve();  
    } 
    return 0;
}