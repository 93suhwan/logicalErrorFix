#include <bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (ll i = x; i < y; i++)
#define DEC(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define nline "\n"
using namespace std;

// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef map<ll,ll> mp;

ll lcm(ll a, ll b) { return (a * (b / __gcd(a, b))); }

// Some constants
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void solve()
{
       ll n;
       cin>>n;
       vi a(n);
       rep(n)
       cin>>a[i];
       sort(all(a));
       ll diff=INT_MAX;
       
  // if((a[n-1]-a[0])%2==0)
FOR(j,0,100)
{
     FOR(i,0,n-1)
     {
         if(a[i+1]-a[i]>1)
         {
             ll k=a[i];
            a[i]=(a[i]+a[i+1])/2;
            a[i+1]=(k+a[i+1])-a[i];
         }

     }

}
debug(a)
  cout<<(*max_element(all(a))-*min_element(all(a)))%2<<nline;

}
signed main()
{

    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    

    return 0;
}