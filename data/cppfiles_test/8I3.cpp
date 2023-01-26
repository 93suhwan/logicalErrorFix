/* Author: Thallium54 {{{
 * Blog: https://blog.tgc-thallium.com/
 * Code library: https://github.com/thallium/acm-algorithm-template
 * }}}*/
#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x) //{{{
#ifndef LOCAL // https://github.com/p-ranav/pprint
#define de(...)
#define de2(...)
#endif
using ll = long long;
using pii = pair<int, int>; //}}}

template <typename T> struct fenwick {
    int n; vector<T> t;
    fenwick(int n_) : n(n_), t(n + 1) {}
    fenwick(const vector<T> &v) : fenwick((int)v.size()) {
        for (int i = 1; i <= n; i++) {
            t[i] += v[i - 1];
            int j = i + (i & -i);
            if (j <= n) t[j] += t[i];
        }
    }
    void add(int i, T x) {
        assert(i >= 0 && i < n);
        for (i++; i <= n; i += i & -i) {
            t[i] += x;
        }
    }
    template <typename U = T> U query(int i) {
        assert(i >= 0 && i < n);
        U res{};
        for (i++; i > 0; i -= i & -i)
            res += t[i];
        return res;
    }
    template <typename U = T> U query(int l, int r) {
        assert(l >= 0 && l <= r && r < n);
        return query<U>(r) - (l ? query<U>(l - 1) : U{});
    }
    int search(T prefix) { // finds first pos s.t. sum(0, pos)>=prefix
        int pos = 0;
        T sum = 0;
        for (int i = __lg(n); i >= 0; i--) {
            // could change < to <= to make it find upper bound
            if (pos + (1 << i) <= n && (sum + t[pos + (1 << i)] < prefix)) {
                pos += (1 << i);
                sum += t[pos];
            }
        }
        return pos;
    }
};
struct HLD {
    vector<vector<int>> g;
    vector<int> pa, dep, heavy, head, pos, posr; // initialize heavy with -1
    int cnt=0;
    fenwick<long long> tr;
    HLD(int n) : g(n), pa(n), dep(n), heavy(n, -1), head(n), pos(n), posr(n), tr(n) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int dfs(int u) {
        int size = 1;
        int mx = 0;
        for (int v : g[u]) {
            if (v != pa[u]) {
                pa[v] = u, dep[v] = dep[u] + 1;
                int csize = dfs(v);
                size += csize;
                if (csize > mx) mx = csize, heavy[u] = v;
            }
        }
        return size;
    }
    void dfs2(int u, int h) {
        head[u] = h, pos[u] = cnt++; //0-based index
        if (heavy[u] != -1) dfs2(heavy[u], h);
        for (int v : g[u]) {
            if (v != pa[u] && v != heavy[u])
                dfs2(v, v);
        }
        posr[u] = cnt;
    }
    void update(int u, int x) {
        int old = tr.query(pos[u], pos[u]);
        tr.add(pos[u], x-old);
    }
    long long pathsum(int u, int v) {
        long long res = 0;
        while (head[u] != head[v]) {
            if (dep[head[u]] < dep[head[v]]) swap(u, v);
            res += tr.query(pos[head[u]], pos[u]);
            u = pa[head[u]];
        }
        if (pos[u] > pos[v]) swap(u, v);
        res += tr.query(pos[u], pos[v]);
        de(res);
        return res;
    }
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (dep[head[u]] > dep[head[v]]) u = pa[head[u]];
            else v = pa[head[v]];
        }
        return dep[u] > dep[v] ? v : u;
    }
};
void test_case() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    HLD g(n);
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.add_edge(u, v);
    }
    g.dfs(0);
    g.dfs2(0, 0);
    for (int i=0; i<n; i++) {
        g.update(i, abs(a[i]));
    }
    while (q--) {
        int op, u, c;
        cin >> op >> u >> c;
        if (op==1) {
            g.update(u, abs(c));
        } else {
            u--, c--;
            cout << g.pathsum(u, c)*2-g.pathsum(u, u)-g.pathsum(c, c) << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;
    while (tt--) {
        test_case();
    }
}
