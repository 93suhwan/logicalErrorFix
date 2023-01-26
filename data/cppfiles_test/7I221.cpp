//BY: YASH JAIN, CF: BitSane
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define May_the_fork_be_with_you ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(),v.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define deb(x) cout<<#x<<": "<<x<<endl;
#define debn(x) cout<<#x<<": "<<x<<"  ";
#define MOD 1000000007
#define mod 998244353
#define INF 1e18
#define ll long long
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define int long long
#define sq(x) ((x)*(x))
typedef vector<int> vi;
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll power(ll x, ll y, ll p = INF) {ll res = 1; x %= p; while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1; x = (x * x) % p;} return res;}
// Do Not use power when calculating powers of 2 (it's inefficient)

// This is lain's segtree template
template<class T>
struct SegTree {
    int n;
    vector<T> t;
    T E = 0;

    T comb(T a, T b) { // Segtree function
        return gcd(a, b);
    }
    SegTree() {}
    SegTree(int _n) : n(_n), t(4 * n + 5) {}
    SegTree(vector<T>& bld) : n(bld.size()), t(4 * n + 5) {
        build(bld, 1, 0, n - 1);
    }
    void build(vector<T>& bld, int node, int tl, int tr) {
        if (tl == tr) {
            t[node] = bld[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(bld, 2 * node, tl, tm);
            build(bld, 2 * node + 1, tm + 1, tr);
            pull(node);
        }
    }
    void pull(int node) { t[node] = comb(t[2 * node], t[2 * node + 1]); }
    T query(int l, int r) {return query(l, r, 1, 0, n - 1);}
    T query(int l, int r, int node, int tl, int tr) {
        if (r < tl || tr < l) return E;
        if (l <= tl && tr <= r) return t[node];
        int tm = (tl + tr) / 2;
        return comb(query(l, r, 2 * node, tl, tm), query(l, r, 2 * node + 1, tm + 1, tr));
    }
    void update(int p, T val) { return update(p, val, 1, 0, n - 1); }
    void update(int p, T val, int node, int tl, int tr) {
        if (tl == tr) {
            t[node] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, val, 2 * node, tl, tm);
        else update(p, val, 2 * node + 1, tm + 1, tr);
        pull(node);
    }
};

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vi a(n), b(n - 1);
    forn(i, n) cin >> a[i];
    forn(i, n - 1) b[i] = abs(a[i] - a[i + 1]);
    SegTree<int> st(b);
    int i = 0, j = 0, res = 0;
    while (j < n - 1) {
        if (st.query(i, j) != 1) {
            res = max(res, j - i + 2);
            j++;
        }
        else i++;
    }
    cout << res << endl;
}

int32_t main() {

#ifndef ONLINE_JUDGE
    // for geting input form input.txt
    freopen("input.txt", "r", stdin);
    // for wrting output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    May_the_fork_be_with_you
    int t = 1;
    int x = 1;
    cin >> t;
    cout << fixed << setprecision(12);
    while (t--) {
        // cout << "Case #" << x << ": ";
        solve();
        x++;
    }

#ifndef ONLINE_JUDGE
    cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}