///   ***   ---   Bismillahir Rahmanir Rahim    ---   ***   ///
/*
* Author : Farhan Sadek Sakib
* Handle: farhancdr
*/
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;
typedef double dl;
typedef unsigned long long int uint64;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef pair<ll, ll> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define endl '\n'
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define print cout
#define sz(x) (int)x.size()
#define szar(x) (int)(sizeof(x)/sizeof(x[0]))
const double PI = acos(-1);
#define set_bits __builtin_popcountll


#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
#define minimum(a)  *min_element(a.begin(), a.end())
#define maximum(a)  *max_element(a.begin(), a.end())

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define file() freopen("input.txt","r",stdin);
#define fileio() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
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
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";



#define dbg(args...) do {cerr << #args << " : "; xdbg(args); } while(0)
void xdbg () {cerr << endl;}
template < typename T, typename ... hello>void xdbg( T arg, const hello &... rest) {cerr << arg << ' ';xdbg(rest...);}

// ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
void precision(int a) {cout << setprecision(a) << fixed;}
const int MAX_N = 1e5 + 1;


void solve(ll tc){
  int n;cin>>n;
  int arr[n+1];
  if(n%2==0){
      print<<"YES"<<endl;
      return;
  }
  for(int i=1;i<n;i++){
      if(arr[i]>arr[i+1]){
          print<<"YES"<<endl;
          return;
      }
  }
  print<<"NO\n";
   
 

}
int main()
{
    optimize();
    ll T;T=1;
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    solve(tc);
    return 0;
}
/*
*****Comment Section**********



*/