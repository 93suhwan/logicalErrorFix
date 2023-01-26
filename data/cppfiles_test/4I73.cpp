#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC target("avx2")

#define deb(x) cout << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define len(x) (ll) x.size()
#define lsb(x) (x) & -(x)
#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2
#define v(x) (ll)(x - 'a')

#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef pair <ld, ld> pld;
typedef pair <ll, ll> pll;

template <class T1, class T2 = less <T1>> using pb_heap = __gnu_pbds::priority_queue <T1, T2, binary_heap_tag>;
template <class T1, class T2 = null_type, class T3 = less <T1>> using pb_map = tree <T1, T2, T3, rb_tree_tag, tree_order_statistics_node_update>;
template <class T1, class T2 = null_type, class T3 = hash <T1>> using pb_umap = gp_hash_table <T1, T2, T3>;
template <class T1, class T2, class T3 = hash <T1>> using umap = unordered_map <T1, T2, T3>;
template <class T> using uset = unordered_set <T>;
template <class T> using vec = vector <T>;

const ll infll = numeric_limits <ll>::max() >> 1;
const ll inf = numeric_limits <ll>::max() >> 1;
const ll N = 2e5 + 1;
const ll mod = 1e9 + 7;
ll n, k, pre[2][N], cnt[2][N], mxm[2];

struct Graph {
    ll hap[N];
    ll sum[N];
    ll cnt[N];
    ll pre[N];
    ll top[N];
    ll wgt[N];
    bool stk[N];
    vec <pii> adj[N];
} graph;

void input() {
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i) {
        cin >> graph.hap[i];
    }
    for (ll i = 1; i < n; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        graph.adj[u].pb({v, w});
        graph.adj[v].pb({u, w});
    }
}

ll count(ll u) {
    graph.cnt[u] = 1;
    graph.stk[u] = true;
    for (pii p: graph.adj[u]) {
        ll v = p.xx;
        if (graph.stk[v]) {
            continue;
        }
        graph.cnt[u] += count(v);
    }
    graph.stk[u] = false;
    return graph.cnt[u];
}

ll centroid(ll u, ll c) {
    graph.stk[u] = true;
    ll res = 0;
    ll mxm = c - graph.cnt[u];
    for (pii p: graph.adj[u]) {
        ll v = p.xx;
        if (graph.stk[v]) {
            continue;
        }
        res = max(res, centroid(v, c));
        mxm = max(mxm, graph.cnt[v]);
    }
    if (mxm <= c / 2) {
        res = u;
    }
    graph.stk[u] = false;
    return res;
}

ll find_centroid(ll u) {
    ll c = count(u);
    return centroid(u, c);
}

void clear() {
    for (ll dim = 0; dim < 2; ++dim) {
        for (ll i = 0; i <= mxm[dim]; ++i) {
            pre[dim][i] = 0;
            cnt[dim][i] = 0;
        }
    }
    mxm[0] = mxm[1] = 0;
}

void update(ll dim, ll pos, ll val) {
    pre[dim][pos] += val;
    cnt[dim][pos]++;
    mxm[dim] = max(mxm[dim], pos);
}

ll count_all(ll root) {
    for (ll dim = 0; dim < 2; ++dim) {
        for (ll i = 1; i <= min(k, mxm[dim]); ++i) {
            pre[dim][i] += pre[dim][i - 1];
            cnt[dim][i] += cnt[dim][i - 1];
            pre[dim][i] %= mod;
        }
    }
    ll result = 0;
    for (ll dim = 0; dim < 2; ++dim) {
        for (ll i = 0; i <= min(k, mxm[dim]); ++i) {
            ll mul = pre[dim][i] - (i? pre[dim][i - 1]: 0);
            ll frq = cnt[dim][i] - (i? cnt[dim][i - 1]: 0);
            if (i != k) {
                result += frq * pre[!dim][min(mxm[!dim], k - i - 1)];
                result += mul * cnt[!dim][min(mxm[!dim], k - i - 1)];
                result -= frq * cnt[!dim][min(mxm[!dim], k - i - 1)] * graph.hap[root];
                result %= mod;
            }
            result += frq * pre[dim][min(mxm[dim], k - i)];
            result += mul * cnt[dim][min(mxm[dim], k - i)];
            result -= frq * cnt[dim][min(mxm[dim], k - i)] * graph.hap[root];
            result %= mod;
        }
    }
    return result;
}

void dfs(ll u) {
    graph.stk[u] = true;
    update(graph.top[u], graph.pre[u], graph.sum[u]);
    for (pii p: graph.adj[u]) {
        ll v = p.xx;
        ll w = p.yy;
        if (graph.stk[v]) {
            continue;
        }
        graph.top[v] = graph.top[u];
        graph.wgt[v] = w;
        graph.sum[v] = graph.sum[u] + graph.hap[v];
        graph.pre[v] = graph.pre[u] + (w != graph.wgt[u]);
        dfs(v);
    }
    graph.stk[u] = false;
}

ll compute(ll root) {
    graph.stk[root] = true;
    graph.sum[root] = graph.hap[root];
    for (pii p: graph.adj[root]) {
        ll v = p.xx;
        ll w = p.yy;
        if (graph.stk[v]) {
            continue;
        }
        graph.pre[v] = 0;
        graph.top[v] = w;
        graph.wgt[v] = w;
        graph.sum[v] = graph.sum[root] + graph.hap[v];
        dfs(v);
    }
    ll result = count_all(root);
    result += 2 * graph.hap[root];
    result += 2 * pre[0][min(k, mxm[0])];
    result += 2 * pre[1][min(k, mxm[1])];
    result %= mod;
    for (pii p: graph.adj[root]) {
        ll v = p.xx;
        ll w = p.yy;
        if (graph.stk[v]) {
            continue;
        }
        graph.pre[v] = 0;
        graph.top[v] = w;
        graph.wgt[v] = w;
        graph.sum[v] = graph.sum[root] + graph.hap[v];
        clear();
        dfs(v);
        result -= count_all(root);
    }
    result = result * (mod + 1 >> 1) % mod;
    clear();
    return result;
}

ll centroid_decomposition(ll u) {
    ll cent = find_centroid(u);
    ll result = compute(cent);
    graph.stk[cent] = true;
    for (pii p: graph.adj[cent]) {
        ll v = p.xx;
        if (!graph.stk[v]) {
            result += centroid_decomposition(v);
            result %= mod;
        }
    }
    return result;
}

void solve() {
    cout << (centroid_decomposition(1) + mod) % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    input();
    solve();
}
