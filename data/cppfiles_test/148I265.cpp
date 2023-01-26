/*OM NAMAH SHIVAY*/
/*Hare Ram Hare Ram, Ram Ram Hare Hare
        Hare Krishna Hare Krishna, Krishna Krishna Hare Hare */
/* Jai Shree Radhe Krishna */
/* AdiShyam */
#include <bits/stdc++.h>
#include<string>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void error() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
}
void output_time() {
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
#define fastio() {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())

#define For(i,a,b) for(int i=a;i<b;i++)
#define VEC(n,m) vector<vector<ll> > mat( n,vector<ll> (m))
#define VEC1 vector<int> 
#define VEC2 vector<long long> 
#define max(a,b) (a < b ? b : a) 
#define min(a,b) ((a > b) ? b : a)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"

#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif


template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

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
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional> // for less
// using namespace __gnu_pbds;

// this is ordered_set in which we have all operations of sets. Additionally we have two more func:
// st.find_by_order(x); => this will return an iterator to the element at index x;
// st.order_of_key(x);=> this will return count of elements that are strictly less than x;
// replace DATA_TYPE with the data you want to store in the ordered_set
// replace less<DATA_TYPE> with any comparator you wish according to which the elements will be arranged.
// typedef tree< DATA_TYPE , null_type, less<DATA_TYPE>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/*---------------------------------------------------------------------------------------------------------------------------*/



ll round_up(ll a, ll b) {return (a + b - 1) / b;} //  round_up(a/b)
vector<ll> allfactors(ll n) {vector<ll>v; for (ll i = 2; i <= sqrt(n); i++) {if (n % i == 0) {v.push_back(i); if ((n / i) != i)v.push_back(n / i);}} v.push_back(n); return v;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) { ll ret ; ll g = __gcd(a, b) ; ret = a / g ; ret = ret * b ; return ret ; }
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
bool isPrime(ll x) {for (ll i = 2; i * i <= x; i++) {if (x % i == 0) return false;} return true;}
vector<ll> z_function(ll n, string s) {vector<ll> z(n); ll l = 0, r = 0; for (ll i = 1; i < n; i++) {if (i <= r) {z[i] = min(r - i + 1, z[i - l]);} while (i + z[i] < n and (s[z[i]] == s[i + z[i]])) {z[i]++;} if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1;}} return z;}
// int const N = 2e5 + 10;

//int spf[N];
//void factor_sieve(){spf[1] = 1;for (int i=2; i<N; i++)spf[i] = i;for(int i=4; i<N; i+=2)spf[i] = 2;for (int i=3; i*i<N; i++){if (spf[i] == i){for (int j=i*i; j<N; j+=i)if (spf[j]==j)spf[j]=i;}}}
//vector<int> getFactorization(int x){vector<int> ret;while (x != 1){ret.push_back(spf[x]);x = x / spf[x];}return ret;}

// returns no. of elements [1,n] that are relatively prime to n.
// ll phi(ll n){ll result = n;for(ll p = 2; p * p <= n; ++p){if (n % p == 0){while (n % p == 0)n /= p;result -= result / p;}}if (n > 1)result -= result / n;return result;}


// ll fact[N];
// void fac() {
//     fact[0] = 1;
//     for (ll i = 1; i < 2e5; i++) {
//         fact[i] = mod_mul(fact[i - 1], i, MOD);
//     }
// }
// ll ncr(int n, int r) {
//     return mod_div(fact[n] , mod_mul(fact[r] , fact[n - r], MOD), MOD);
// }

// void Frequency(vector<int> v)
// {
//     map<int, int> M;
//      for (int i = 0; v[i]; i++) {
//          if (M.find(v[i]) == M.end()) {
//             M[v[i]] = 1;}
//         else  M[v[i]]++; }}


const int MAX=1e6+1;
bool prime[MAX+1];
 
void sieve1(){ //prime or not
    for(int i=0;i<=MAX;i++) prime[i]=1;
 
    prime[0]=prime[1]=0;
 
    for(ll i=4;i<=MAX;i+=2) prime[i]=0;
 
    for (int p=3; p*p<=MAX; p+=2){
        if (prime[p] == 1)
            for (int i=p*2; i<=MAX; i += p){
                prime[i] = 0;
            }
      }
}


/*--------------------------------------------------------------------------------------------------------------------------*/
// Read Question Twice.
// Always check for contraints.
// Think twice before submitting code.

void solve() 
{
    ll w,h,flag=0,maxi=INT_MIN,ans=0;
    cin>>w>>h;
    for(int i=0;i<4;i++)
    {
        ll k;
        cin>>k;
        VEC1 v(k);
        for(int j=0;j<k;j++)
        {
            cin>>v[j];
        }
        if(maxi<=(v[k-1]-v[0]))
        {
            if(i==0 || i==1)
            {
                maxi=v[k-1]-v[0];
                ans=max(ans,maxi*h);
            }
               
            else
            {
                maxi=v[k-1]-v[0];
                ans=max(ans,maxi*w);
            }

        }
    }
    cout<<ans<<endl;
}


int main()
{
    init();
    error();

    fastio();

    sieve1();
    int t = 1;
    cin >> t;
    while(t--)
        solve();

   
   output_time();
}




