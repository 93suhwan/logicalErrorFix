/************************* Pragmas *************************/
/*#pragma GCC optimize("O3")//using O2 isn't a bad idea.
#pragma GCC optimize("Ofast") //may result in inaccurate calculations in float.
#pragma GCC optimize ("unroll-loops") // https://code-examples.net/en/q/17133ec
#pragma GCC
target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")//vectorization
//Consider using user defined function for better optimization.
/****************************************************/

/************************* Directives *************************/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  // For pbds.Don't use tree as variable name.
#include <ext/pb_ds/tree_policy.hpp>
/***************************************************************/

/************************* Namespaces *************************/
using namespace std;
using namespace __gnu_pbds;
/*************************************************************/

/************************* Macros *************************/
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);  // Don't use scanf/printf
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mem(x, i) memset(x, i, sizeof(x))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
//#define sz(x)       (int)x.size()
#define Case(t) for (int ks = 1; ks <= t; ks++)
#define fileout freopen("output.txt", "w", stdout)
#define filein freopen("in.txt", "r", stdin)
//#define _        __LINE__
#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
        \                                 \
    }
/**********************************************************/

/************************* Type definitions *************************/
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;  //%Lf
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
/*******************************************************************/

/************************* PBDS *************************/
template <typename T>
using orderedSet =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*******************************************************************/

/************************* Input *************************/
void read(int &x) { scanf("%i", &x); }
void read(ll &x) { scanf("%lld", &x); }
void read(char *x) { scanf("%s", x); }
void read(double &x) { scanf("%lf", &x); }
void read(string &x) {
    char y[1000006];
    scanf("%s", &y);
    x = y;
}
int ri() {
    int x;
    read(x);
    return x;
}
template <typename T1, typename T2>
void read(pair<T1, T2> &x) {
    read(x.first);
    read(x.second);
}
template <typename T, typename... A>
void read(T &x, A &...args) {
    read(x);
    read(args...);
}
/*********************************************************/

/************************* Output *************************/
#define pf printf
#define yes puts("YES")
#define no puts("NO")
#define endl '\n'
/**********************************************************/

/************************* Loops *************************/
#define rep(i, begin, end)                              \
    for (__typeof(end) i = (begin) - ((begin) > (end)); \
         i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// This loop works in both direction and also for iterator
// runs till end-1
/********************************************************/

/************************* Debug Tool *************************/
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ",\n"[++it == istream_iterator<string>()];
    err(it, args...);
}
/*************************************************************/
/************************* Graph Moves *************************/
// const int fx[] = {+1, -1, +0, +0};//, +1, +1, -1, -1};// exclude last four
// when side adjacent const int fy[] = {+0, +0, +1, -1};//, +1, -1, +1, -1};
const int fx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int fy[] = {-1, 1, -2, 2, -2, 2, -1, 1}; /* Knights Move*/
/***************************************************************/

/************************* Bit Magics *************************/
/* __builtin_popcount(x) - number of set bits*/
/* __builtin_ffs(x)      - 1+least significant set bit position*/
/* __builtin_clz(x)      - number of leading 0-bits of x which starts from most
 * significant bit position*/
/* __builtin_ctz(x)      - number of trailing 0-bits of x which starts from
 * least significant bit position*/
/*   set i'th bit of N -> N |= (1<<i) */
/* reset i'th bit of N -> N = N & ~(1<<i) */
/* check i'th bit of N -> N&(1<<i)*/
/**************************************************************/

/************************* Mathematics *************************/
// For big mod
const int MOD = 998244353;
template <typename T>
inline T gcd(T a, T b) {
    T c;
    while (b) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}  // better than __gcd
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}
/**************************************************************/
// order_of_key(k) - number of element strictly less than k.
// find_by_order(k) - k'th element in set.(0 indexed)(iterator)
/************************* Numeric Values *************************/
const int INF = 0x3f3f3f3f;  // useful for memset
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-7;
const int mx = 2e5 + 5;  // CHECK here for every problem
const int mod = 998244353;
/******************************************************************/

/*--------------------Start Here------------------*/

void solve() {
    int n = ri();
    int a[n][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            read(a[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int x = 0, y = 0, z = 0;
            for (int k = 0; k < n; k++) {
                if (a[k][i] && a[k][j])
                    z++;
                else if (a[k][i])
                    x++;
                else
                    y++;
            }
            if (x <= n / 2 && y <= n / 2) {
                yes;
                return;
            }
        }
    }
    no;
    return;
}
int main() {
    int t = ri();
    while (t--) {
        solve();
    }
}