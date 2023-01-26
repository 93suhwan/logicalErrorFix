#include <bits/stdc++.h>
using namespace std;
template<typename X, typename Y>
pair<X, Y> neg(pair<X, Y> p) {
    return {-p.first, -p.second};
}
template<typename T, typename Matroid1, typename Matroid2>
vector<int> weighted_matroid_intersection(int N, vector<T> w, Matroid1& M1, Matroid2& M2) {
    vector<bool> b(N), target(N), vis(N);
    vector<int> I[2], from(N);
    vector<T> p(N);
    vector<pair<T, int>> d(N);
    auto check_edge = [&](int u, int v) {
        return (b[u] && M1.oracle(u, v)) || (b[v] && M2.oracle(v, u));
    };
    while (true) {
        I[0].clear(), I[1].clear();
        for (int u = 0; u < N; ++u) {
            I[b[u]].push_back(u);
        }
        M1.build(I[1]), M2.build(I[1]);
        fill(d.begin(), d.end(), pair(numeric_limits<T>::max(), numeric_limits<int>::max()));
        fill(target.begin(), target.end(), false);
        fill(vis.begin(), vis.end(), false);
        fill(from.begin(), from.end(), -1);
        for (auto u : I[0]) {
            target[u] = M2.oracle(u);
            if (M1.oracle(u)) {
                d[u] = {w[u] - p[u], 0};
            }
        }
        bool converged = true;
        while (true) {
            int u = -1;
            for (int v = 0; v < N; ++v) {
                if (not vis[v] && d[v].second < N && (u == -1 || d[v] < d[u])) {
                    u = v;
                }
            }
            if (u == -1) break;
            if (target[u]) {
                converged = false;
                for (int v = u; v != -1; v = from[v]) {
                    b[v] = !b[v];
                    w[v] *= -1;
                }
                for (int v = 0; v < N; ++v) {
                    p[v] += min(d[u].first, d[v].first);
                }
                break;
            }
            vis[u] = true;
            for (auto v : I[!b[u]]) {
                if (vis[v] || !check_edge(u, v)) continue;
                pair<T, int> nd(d[u].first + w[v] + p[u] - p[v], d[u].second + 1);
                if (nd < d[v]) {
                    from[v] = u;
                    d[v] = nd;
                }
            }
        }
        if (converged) break;
    }
    return I[1];
}
struct GraphicMatroid {
    int N, M;
    vector<array<int, 2>> edges;
    vector<vector<int>> E;
    vector<int> component, L, R;
    GraphicMatroid(int N, const vector<array<int, 2>>& edges_) : N(N), M((int)edges_.size()), edges(edges_), E(N), component(N), L(N), R(N) {}
    int timer = 0;
    void dfs(int u) {
        L[u] = timer++;
        for (auto v : E[u]) {
            if (L[v] != -1) continue;
            component[v] = component[u];
            dfs(v);
        }
        R[u] = timer;
    }
    void build(const vector<int>& I) {
        timer = 0;
        for (int u = 0; u < N; ++u) {
            E[u].clear();
            L[u] = -1;
        }
        for (auto e : I) {
            auto [u, v] = edges[e];
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for (int u = 0; u < N; ++u) {
            if (L[u] != -1) continue;
            component[u] = u;
            dfs(u);
        }
    }
    bool is_ancestor(int u, int v) const {
        return L[u] <= L[v] && L[v] < R[u];
    }
    bool oracle(int e) const {
        return component[edges[e][0]] != component[edges[e][1]];
    }
    bool oracle(int e, int f) const {
        if (oracle(f)) return true;
        int u = edges[e][L[edges[e][0]] < L[edges[e][1]]];
        return is_ancestor(u, edges[f][0]) != is_ancestor(u, edges[f][1]);
    }
};
struct PartitionMatroid {
    vector<int> cap, color, d;
    PartitionMatroid(const vector<int>& cap, const vector<int>& color) : cap(cap), color(color), d(size(cap)) {}
    void build(const vector<int>& I) {
        fill(d.begin(), d.end(), 0);
        for (auto u : I) {
            ++d[color[u]];
        }
    }
    bool oracle(int u) const {
        return d[color[u]] < cap[color[u]];
    }
    bool oracle(int u, int v) const {
        return color[u] == color[v] || oracle(v);
    }
};
struct DSU {
    vector<int> p, rk;
    DSU(int N) : p(N), rk(N) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rk[u] < rk[v]) swap(u, v);
        p[v] = u, rk[u] += (rk[u] == rk[v]);
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> d(K);
    for (int u = 0; u < K; ++u) {
        cin >> d[u];
    }
    d.push_back(numeric_limits<int>::max());
    vector<vector<int>> w(N, vector<int>(N));
    vector<array<int, 3>> edges;
    for (int u = 0; u < N; ++u) {
        for (int v = u + 1; v < N; ++v) {
            cin >> w[u][v];
            w[v][u] = w[u][v];
            if (u >= K) {
                edges.push_back({w[u][v], u, v});
            }
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu(N);
    vector<array<int, 2>> mst_edges;
    for (auto [x, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst_edges.push_back({u, v});
        }
    }
    int M = K * (K - 1) / 2, ans = numeric_limits<int>::max();
    for (int mask = 0; mask < (1 << M); ++mask) {
        auto cap = d;
        int cost = 0;
        DSU dsu(K);
        bool good = true;
        for (int u = 0, ptr = 0; u < K; ++u) {
            for (int v = u + 1; v < K; ++v, ++ptr) {
                if (mask >> ptr & 1) {
                    if (cap[u] == 0 || cap[v] == 0 || !dsu.unite(u, v)) {
                        good = false;
                    }
                    --cap[u], --cap[v];
                    cost += w[u][v];
                }
            }
        }
        if (!good) continue;
        vector<array<int, 2>> edges;
        vector<int> weights, color;
        for (int u = 0; u < K; ++u) {
            for (int v = K; v < N; ++v) {
                edges.push_back({dsu.find(u), v});
                color.push_back(u);
                weights.push_back(w[u][v]);
            }
        }
        for (auto [u, v] : mst_edges) {
            edges.push_back({u, v});
            color.push_back(K);
            weights.push_back(w[u][v]);
        }
        GraphicMatroid G(N, edges);
        PartitionMatroid P(cap, color);
        auto I = weighted_matroid_intersection((int)edges.size(), weights, P, G);
        vector<int> J;
        for (auto j : I) {
            G.build(J);
            P.build(J);
            assert(G.oracle(j) && P.oracle(j));
            J.push_back(j);
            cost += weights[j];
        }
        if ((int)I.size() + __builtin_popcount(mask) == N - 1) {
            ans = min(ans, cost);
        }
    }
    cout << ans << '\n';
    exit(0);
}
