#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define REPL(i,a,n) for(i=a;i<=(n); i+=1)
#define REPr(i,n) for(i=n-1;i>=0;i-=1)

#define MOD 1000000007

#define INF 0x3f3f3f3f
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vvi vector<vector<int>>
//#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define vpii vector<pii>
#define mp make_pair
#define F first
#define S second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define allof(x) x.begin(), x.end()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define DEBUG 1
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define set_bits __builtin_popcountll
#define PI 3.141592653589793238462
#define fo(i,n) for(int i=0;i<n;i++)


inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

typedef vector<ll> vll;
typedef set<int>::iterator sit;
typedef unordered_set<int>::iterator usit;
typedef multiset<int>::iterator msit;
typedef unordered_multiset<int>::iterator umsit;
typedef vector<ll>::iterator vllit;
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(double t) {cout << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}" << endl;}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(ordered_set <T> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]" << endl;}
 
ll MAX3(ll x , ll y, ll z){
    ll t = max(x,y);
    return max(t,z);
}

ll power(ll x, ll n) {
    ll i,ans = 1;
    REPL(i,1,n){
        ans = ans*x; 
    }
    return ans ;
}

ll modInv(ll a) {
    return PowMod(a, MOD-2);
}

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

/*--------------------------------------------------------------------------------------------------------------------------*/

bool check(vector <vll> &p, int m, int n, ll val) {
    map <int, int> mpx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (p[j][i] >= val) mpx[j]++;
        }
    }

    for (int j = 0; j < m; j++) {
        if (mpx[j] >= 2) return true;
    }

    return false;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector <vll> p(m, vll (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    if (m <= n-1) {
        ll ans = 1e18;
        for (int i = 0; i < n; i++) {
            ll maxx = -1;
            for (int j = 0; j < m; j++) {
                maxx = max(maxx, p[j][i]);
            }
            ans = min(ans, maxx);
        }
        cout << ans << endl;
        return;
    }

    ll ans = 1e18;
    map <int, int> indices;
    for (int i = 0; i < n; i++) {
        ll maxx = -1;
        int idx = -1;
        for (int j = 0; j < m; j++) {
            if (maxx < p[j][i]) {
                idx = j;
                maxx = p[j][i];
            }
        }
        for (int j = 0; j < m; j++) {
            if (maxx == p[j][i]) indices[j]++;
        }

        ans = min(ans, maxx);
    }

    for (int i = 0; i < m; i++) {
        if (indices[i] >= 2) {
            cout << ans << endl;
            return;
        } 
    }

    ll r = 1e9 + 5, l = 1;
    ans = 1;
    while (l <= r) {
        ll cand = (l + r) / 2LL;
        if (check(p, m, n, cand)) {
            ans = max(ans, cand);
            l = cand + 1;
        }
        else {
            r = cand - 1;
        }
    }

    cout << ans << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}