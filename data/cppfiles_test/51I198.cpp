#include <bits/stdc++.h>
using namespace std;
// 'heavy' matroid should be M2
template<typename T, typename Matroid1, typename Matroid2>
vector<int> weighted_matroid_intersection(int N, const vector<T>& w, Matroid1& M1, Matroid2& M2) {
    vector<bool> b(N);
    vector<int> I[2];
    while (true) {
        for (int t : {0, 1}) I[t].clear();
        vector<T> l(N);
        for (int u = 0; u < N; ++u) {
            I[b[u]].push_back(u);
            l[u] = (b[u] ? -1 : +1) * w[u];
        }
        M1.build(I[1]), M2.build(I[1]);
        vector<bool> target(N);
        queue<int> q;
        vector<pair<T, int>> d(N, {numeric_limits<T>::max(), numeric_limits<int>::max()});
        for (auto u : I[0]) {
            target[u] = M2.oracle(u);
            if (M1.oracle(u)) {
                q.push(u);
                d[u] = {w[u], 0};
            }
        }
        vector<int> p(N, -1);
        int t = -1;
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            if (target[u] && (t == -1 || d[t] > d[u])) t = u;
            for (auto v : I[!b[u]]) {
                pair<T, int> nd(d[u].first + l[v], d[u].second + 1);
                if (nd >= d[v]) continue;
                if ((b[u] && M1.oracle(u, v)) || (b[v] && M2.oracle(v, u))) {
                    p[v] = u;
                    d[v] = nd;
                    q.push(v);
                }
            }
        }
        if (t == -1) break;
        for (int v = t; v != -1; v = p[v]) b[v] = !b[v];
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
        R[u] = timer - 1;
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
        return L[u] <= L[v] && L[v] <= R[u];
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> d(N, N);
    for (int u = 0; u < K; ++u) {
        cin >> d[u];
    }
    vector<vector<int>> w(N, vector<int>(N));
    for (int u = 0; u < N; ++u) {
        for (int v = u + 1; v < N; ++v) {
            cin >> w[u][v];
            w[v][u] = w[u][v];
        }
    }
    int M = K * (K - 1) / 2, ans = numeric_limits<int>::max();
    for (int mask = 0; mask < (1 << M); ++mask) {
        vector<int> label(N), cap = d;
        iota(label.begin(), label.end(), 0);
        int cost = 0;
        for (int u = 0, ptr = 0; u < K; ++u) {
            for (int v = u + 1; v < K; ++v, ++ptr) {
                if ((mask >> ptr & 1) && cap[u] > 0 && cap[v] > 0) {
                    label[v] = label[u];
                    --cap[u], --cap[v];
                    cost += w[u][v];
                }
            }
        }
        vector<array<int, 2>> edges;
        vector<int> weights, color;
        for (int u = 0; u < N; ++u) {
            for (int v = u + 1; v < N; ++v) {
                if (u < K && v < K) continue;
                edges.push_back({label[u], label[v]});
                color.push_back(u);
                weights.push_back(w[u][v]);
            }
        }
        GraphicMatroid G(N, edges);
        PartitionMatroid P(cap, color);
        auto I = weighted_matroid_intersection((int)edges.size(), weights, P, G);
        for (auto j : I) {
            cost += weights[j];
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    exit(0);
}
