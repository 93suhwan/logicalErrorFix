#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ff                  first
#define ss                  second
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define lb                  lower_bound
#define ub                  upper_bound
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define sz(v)               (int)v.size()
#define ps(y)               cout << fixed << setprecision(y)
#define ms(arr, v)          memset(arr, v, sizeof(arr))
#define all(v)              v.begin(), v.end()
#define rall(v)             v.rbegin(), v.rend()
#define trav(x, v)          for(auto &x: v)
#define w(t)                int t; cin >> t; while(t--)
#define rep(i, a, b)        for(int i = a; i <= b; i++)
#define rrep(i, a, b)       for(int i = a; i >= b; i--)
#define rep0(i, n)          rep(i, 0, n - 1)
#define rrep0(i, n)         rrep(i, n - 1, 0)
#define rep1(i, n)          rep(i, 1, n)
#define rrep1(i, n)         rrep(i, n, 1)
#define inp(arr, n)         rep0(i, n) cin >> arr[i];

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef map<ll, ll> mii;
typedef map<char, ll> mci;
typedef priority_queue<ll> pq_mx;
typedef priority_queue<ll, vi, greater<>> pq_mn;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*
 * find_by_order(i) -> returns an iterator to the element at ith position (0 based)
 * order_of_key(i)  -> returns the position of element i (0 based)
 */

const int N = 3e5 + 5;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll inf = 2e18;
const ld eps = 1e-10, pi = acos(-1.0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void fio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

ll n, m, q, odds[N], cnt[N];
bool vis[N];
vp gr[N], edg;
vi path;

void dfs(int cur, vi &v, int b) {
    if (vis[cur]) return;
    v.pb(cur), vis[cur] = true;
    trav(neigh, gr[cur]) {
        if (neigh.ff == b and odds[b] < (cnt[neigh.ss] & 1) + odds[cur]) path = v;
        odds[neigh.ff] = max(odds[neigh.ff], (cnt[neigh.ss] & 1) + odds[cur]);
        dfs(neigh.ff, v, b);
    }
    v.pop_back();
}

void updDfs(int cur, int &i) {
    if (i == sz(path)) return;
    trav(neigh, gr[cur]) {
        if (neigh.ff == path[i]) {
            ++cnt[neigh.ss], ++i, updDfs(neigh.ff, i);
            break;
        }
    }
}

void Dfs(int cur) {
    vis[cur] = true;
    trav(neigh, gr[cur]) {
        if (!vis[neigh.ff]) Dfs(neigh.ff);
    }
}

int main() {
    fio();

    cin >> n >> m;
    rep0(x, m) {
        int u, v;
        cin >> u >> v;
        gr[u].eb(v, x), gr[v].eb(u, x);
        edg.eb(u, v);
    }

    cin >> q;
    vvi ans;
    rep0(x, q) {
        int a, b;
        cin >> a >> b;
        rep1(y, n) vis[y] = false;
        odds[a] = 0, odds[b] = -1;
        vi v;
        dfs(a, v, b);
        path.pb(b);
//        trav(y, path) cout << y << " ";
//        cout << endl;
        int i = 1;
        ans.pb(path), updDfs(path[0], i);
    }
    bool can = true;
    rep0(x, m) can &= (cnt[x] % 2 == 0);
    if (can) {
        cout << "YES\n";
        trav(v, ans) {
            cout << sz(v) << endl;
            trav(x, v) cout << x << " ";
            cout << endl;
        }
    } else {
        cout << "NO\n";
        rep1(x, n) gr[x].clear(), vis[x] = false;
        rep0(x, m) {
            if (cnt[x] & 1) {
                int u = edg[x].ff, v = edg[x].ss;
                gr[u].eb(v, 0), gr[v].eb(u, 0);
            }
        }
        int rem = 0;
        rep1(x, n) {
            if (vis[x] or gr[x].empty()) continue;
            ++rem, Dfs(x);
        }
        cout << rem;
    }

    return 0;
}