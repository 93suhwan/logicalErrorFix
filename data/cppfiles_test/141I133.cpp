#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef long long int ll;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<ll>, rb_tree_tag,
                    tree_order_statistics_node_update>
                    ordered_set;
 
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
template <class T> void _print(ordered_set v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
struct pp{int x; char y; int z;};
const int MOD= 998244353, inf=INT_MAX, inff=INT_MIN, linf=LONG_MAX;
const int N=500000+1;
ll expo1(ll a, ll b)  {ll res = 1; while (b > 0) {    if (b & 1)res = (res * a);     a = (a * a);     b = b >> 1;} return res;}
ll expo(ll a, ll b)   {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % MOD; a = (a * a) % MOD; b = b >> 1;} return res;}
int LOG(ll n, ll x) {int ans=-1;while(n){    ans++, n/=x;}return ans;}

vcl v, v1;
void f()
{
  rep(j, 1, 100000)
  {
    ll i=j;
    v.pb(i*i), v.pb(i*i*i);
  }
  sort(all(v));
  v1.pb(v[0]);
  rep(i, 1, v.sz)
  {
    if(v[i]!=v1.back())
      v1.pb(v[i]);
  }

}

void Solve()
{ 
  // ll n; cin>>n;
  // ll a[n]; rep(i, 0, n) cin>>a[i];
  // ll n, m; cin>>n>>m;
  string s, t; cin>>s>>t;
  // ll a, b, c; cin>>a>>b>>c;
  if(s.sz>t.sz)
  {
    cout<<-1<<enl;
  }
  int I=t.sz-1;
  string ans="";
  for(int i=s.sz-1; i>=0; i--)
  {
    // debug(I)
    if(I<0)
    {
      cout<<-1<<enl;
    }
    if(t[I]>=s[i]) 
    {
      ans.pb('0'+t[I]-s[i]);
    }
    else if(I==0)
    {
      cout<<-1<<enl;
    }
    else
    {
      // debug(I)
    // debug(t[I]) debug(s[i])
      string p="";
      p.pb(t[I]);
      I--, p.pb(t[I]);
      reverse(all(p));
      int j=stoi(p);
      int c=s[i]-'0';
      if(j-c>=10)
      {
        cout<<-1<<enl;
      }
      // debug(j)
      // debug(((s[I]-'0')))
      // debug(c)
      ans.pb('0'+(j-c));
      // debug(ans)
    }
    I--;
  }
  while(I>=0)
  {
    ans.pb(t[I--]);
  }
  // debug(ans)
  for(int i=ans.sz-1; i>0; i--)
  {
    if(ans[i]=='0') ans.pop_back();
    else break;
  }
  // debug(I)
  reverse(all(ans));
  // if(I>=0)
  // {
  //   cout<<-1<<enl;
  // }

  cout<<ans<<endl;




}

int main()
{ 
    fast
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    int T=1;

    // SieveOfEratosthenes();
    f();
    
    cin >> T;
    while (T--)
    {
        Solve();  
    } 
    return 0;
}