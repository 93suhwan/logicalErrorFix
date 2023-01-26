#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define int long long
#define pb push_back
#define x first
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#undef M_PI
#define M_PI 3.14159265358979323846264338327950288419

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using big = __int128;

template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}

inline ld randld(ld l = INT_MIN, ld r = INT_MAX) {
    return uniform_real_distribution<ld>(l, r)(rng);
}

const int INF = 2e9 + 1;
const int MOD = 998244353; /// think
const ll LINF = 2e18 + 11;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside (int x, int y, int n, int m) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

template<class T> bool umin (T &a, T b) {return a > b ? (a = b, true) : false; }
template<class T> bool umax (T &a, T b) {return a < b ? (a = b, true) : false; }

inline int mul (int a, int b, int m = MOD) {
    return ((ll)a * b) % m;
}

inline int binpow (int a, int n, int m = MOD) {
    int ans = 1;
    for (; n; n >>= 1) {
        if (n & 1) ans = mul(ans, a, m);
        a = mul(a, a, m);
    }
    return ans;
}

inline void add (int &a, int x, int m = MOD) {
    a += x;
    if (a >= m) a -= m;
    if (a < 0) a += m;
}

inline int sum (int a, int b, int m = MOD) {
    a += b;
    if (a >= m) a -= m;
    if (a < 0) a += m;
    return a;
}

inline int inv (int x, int m = MOD) {
    return binpow(x, m - 2, m); /// only if m is prime
}

vector <int> f, fi;

inline void precalc_f (int n, int m = MOD) {
    f.resize(n);
    fi.resize(n);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        f[i] = mul(f[i - 1], i, m);
    }
    fi[n - 1] = inv(f[n - 1], m);
    for (int i = n - 2; i >= 0; i--) {
        fi[i] = mul(fi[i + 1], i + 1, m);
    }
}

inline int A (int n, int k, int m = MOD) {
    return mul(f[n], fi[n - k], m);
}

inline int C (int n, int k, int m = MOD) {
    return mul(A(n, k), fi[k], m);
}



inline void test_case () {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto &i : a) cin >> i;
    map <int, array<int, 2> > dp;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        auto d_i = dp[a[i]];
        auto d_i_ = dp[a[i] + 1];
        auto d__i = dp[a[i] - 1];
        add(dp[a[i] + 1][0], d_i[0]);
        add(dp[a[i] - 1][1], d__i[0]);
        add(dp[a[i] - 1][1], d__i[1]);
//        add(dp[a[i] + 1][0], d_i[1]);
        add(dp[a[i] + 1][0], d_i_[0]);
        add(dp[a[i] + 1][0], d_i_[1]);
    }
    int ans = MOD - 1;
    for (auto &i : dp) {
        add(ans, i.y[0]);
        add(ans, i.y[1]);
    }
    cout << ans << '\n';
}

main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        test_case();
    }
}
