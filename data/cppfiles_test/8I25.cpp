#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2,bmi,bmi2")
using namespace std;
using ll = long long int;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

/**
 * Point-update Segment Tree
 * Source: kactl
 * Description: Iterative point-update segment tree, ranges are half-open i.e [L, R).
 *              f is any associative function.
 * Time: O(logn) update/query
 */

template<class T, T unit = T()>
struct SegTree {
    T f(T a, T b) { return a+b; }
    vector<T> s; int n;
    SegTree(int _n = 0, T def = unit) : s(2*_n, def), n(_n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

const int N = 1e5 + 5;
const int LOG = 19;
int jump[LOG][N];

struct HLD {
    int N, tim = 0;
    vector<vector<int>> adj;
    vector<int> par, siz, depth, rt, pos, out;
    SegTree<ll> tree;
    HLD(vector<vector<int>> adj_)
        : N(size(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N),pos(N),out(N), tree(N){ dfsSz(0); dfsHld(0); }
    void dfsSz(int v) {
        if (par[v] != -1) {
            adj[v].erase(find(begin(adj[v]), end(adj[v]), par[v]));
            jump[0][v] = par[v];
            for (int level = 1; level < LOG; ++level)
                jump[level][v] = jump[level-1][jump[level-1][v]];
        }
        for (int& u : adj[v]) {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    void dfsHld(int v) {
        pos[v] = tim++;
        for (int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
        out[v] = tim;
    }
    template <class B> void process(int u, int v, B op) {
        for (; rt[u] != rt[v]; v = par[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u], pos[v] + 1);
    }
    // void modifyPath(int u, int v, int val) {
    //     process(u, v, [&](int l, int r) { tree->add(l, r, val); });
    // }
    void modify (int u, int val) {
        tree.update(pos[u], val);
    }
    ll queryPath(int u, int v) { // Modify depending on problem
        ll res = 0;
        process(u, v, [&](int l, int r) {
                res += tree.query(l, r);
        });
        return res;
    }
    // int querySubtree(int v) { // modifySubtree is similar
    //     return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    // }
};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i+1 < n; ++i) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    HLD hld(adj);
    auto is_anc = [&] (int u, int v) {
        return hld.pos[u] <= hld.pos[v] and hld.out[u] >= hld.out[v];
    };
    auto get_highest = [&] (int u, int v) {
        for (int level = LOG-1; level >= 0; --level)
            if (!is_anc(jump[level][u], v))
                u = jump[level][u];
        return u;
    };
    auto lca = [&] (int u, int v) {
        if (is_anc(u, v)) return u;
        return hld.par[get_highest(u, v)];
    };

    const int MAGIC = 350;
    vector<int> heavy;
    for (int i = 0; i < n; ++i)
        if (deg[i] >= MAGIC)
            heavy.push_back(i);
    for (int u = 0; u < n; ++u) {
        if (deg[u] >= MAGIC) continue;
        for (int v : adj[u]) {
            if (deg[v] >= MAGIC) continue;

            if (hld.pos[u] < hld.pos[v]) hld.modify(v, max(abs(a[u] + a[v]), abs(a[u] - a[v])));
            else hld.modify(u, max(abs(a[u] + a[v]), abs(a[u] - a[v])));
        }
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, c; cin >> u >> c; --u;
            a[u] = c;
            if (deg[u] < MAGIC) {
                for (int v : adj[u]) {
                    if (deg[v] >= MAGIC) continue;

                    if (hld.pos[u] < hld.pos[v]) hld.modify(v, max(abs(a[u] + a[v]), abs(a[u] - a[v])));
                    else hld.modify(u, max(abs(a[u] + a[v]), abs(a[u] - a[v])));
                }
            }
        }
        else {
            int u, v; cin >> u >> v; --u, --v;
            int l = lca(u, v);
            ll res = hld.queryPath(u, v) - hld.queryPath(l, l);
            for (int x : heavy) {
                int ct = is_anc(x, u) + (1<<is_anc(x, v));
                if (ct == 0) continue;
                else if (ct == 1) {
                    int y = get_highest(u, x);
                    res += max(abs(a[x] + a[y]), abs(a[x] - a[y]));
                    y = hld.par[x];
                    res += max(abs(a[x] + a[y]), abs(a[x] - a[y]));
                }
                else if (ct == 2) {
                    int y = get_highest(v, x);
                    res += max(abs(a[x] + a[y]), abs(a[x] - a[y]));
                    y = hld.par[x];
                    res += max(abs(a[x] + a[y]), abs(a[x] - a[y]));
                }
                else {
                    int y = get_highest(u, x);
                    res += max(abs(a[x] + a[y]), abs(a[x] - a[y]));
                    y = get_highest(v, x);
                    res += max(abs(a[x] + a[y]), abs(a[x] - a[y]));
                }
            }
            cout << res << '\n';
        }
    }
}