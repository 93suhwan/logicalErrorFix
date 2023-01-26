#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

struct centroid_forest {
    vector<int> parent, depth, roots;

    explicit centroid_forest(const vector<vector<int>>& tree) {
        int N = tree.size();
        parent.assign(N, -1);
        depth.assign(N, -1);

        vector<int> subsize(N);

        auto subsize_dfs = y_combinator([&](auto self, int u, int p) -> void {
            subsize[u] = 1;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u);
                    subsize[u] += subsize[v];
                }
            }
        });

        auto centroid_dfs = y_combinator(
            [&](auto self, int u, int p, int cp, int S) -> pair<int, int> {
                int processed = 0;

                bool changed;
                do {
                    changed = false;
                    for (int v : tree[u]) {
                        while (v != p && depth[v] == -1 && subsize[v] > S / 2) {
                            auto [more, root] = self(v, u, cp, S);
                            subsize[u] -= more;
                            S -= more;
                            processed += more;
                            cp = root;
                            changed = true;
                        }
                    }
                } while (changed);

                // backtrack if u is not a centroid child of cp; else recurse on children
                if (S - subsize[u] > S / 2) {
                    return make_pair(processed, cp);
                }

                parent[u] = cp;
                depth[u] = cp != -1 ? depth[cp] + 1 : 0;

                for (int v : tree[u]) {
                    if (v != p && depth[v] == -1) {
                        self(v, u, u, subsize[v]);
                    }
                }

                return make_pair(processed + subsize[u], u);
            });

        for (int u = 0; u < N; u++) {
            if (depth[u] == -1) {
                subsize_dfs(u, -1);
                centroid_dfs(u, -1, -1, subsize[u]);
            }
            if (parent[u] == -1) {
                roots.push_back(u);
            }
        }
    }

    int num_nodes() const { return parent.size(); }

    int ancestor(int u, int steps) const {
        while (steps--)
            u = parent[u];
        return u;
    }

    int below(int u, int a) const { return ancestor(u, depth[u] - depth[a] - 1); }

    int lca(int u, int v) const {
        while (depth[u] > depth[v])
            u = parent[u];
        while (depth[u] < depth[v])
            v = parent[v];
        while (u != v)
            u = parent[u], v = parent[v];
        return u;
    }

    int findroot(int u) const {
        while (parent[u] != -1)
            u = parent[u];
        return u;
    }

    bool conn(int u, int v) const { return findroot(u) == findroot(v); }
};

template <typename T, typename BinaryFn>
struct centroid_any_sparse_table : centroid_forest {
    vector<vector<T>> table;
    BinaryFn combine;

    template <typename InitFn, typename ExtendFn>
    centroid_any_sparse_table(vector<vector<int>>& tree, const InitFn& init,
                              const ExtendFn& extend, const BinaryFn& op = BinaryFn())
        : centroid_forest(tree), combine(op) {
        int N = num_nodes(), D = *max_element(begin(depth), end(depth));
        table.assign(D + 1, vector<T>(N));

        vector<int> bfs(N), prev(N);

        for (int root = 0; root < N; root++) {
            int d = depth[root];
            table[d][root] = init(root);
            prev[root] = -1;
            bfs[0] = root;
            for (int i = 0, S = 1; i < S; i++) {
                int u = bfs[i];
                for (int v : tree[u]) {
                    if (depth[v] > d && v != prev[u]) {
                        table[d][v] = extend(table[d][u], u, v);
                        prev[v] = u;
                        bfs[S++] = v;
                    }
                }
            }
        }
    }

    auto query(int u, int v) const {
        int a = lca(u, v), d = depth[a];
        return combine(table[d][u], table[d][v]);
    }
};

struct Query {
    int id, u, capacity;

    friend bool operator<(const Query& a, const Query& b) {
        return make_pair(a.capacity, a.id) > make_pair(b.capacity, b.id);
    }
};

struct Edge {
    int capacity, toll, u, v;

    friend bool operator<(const Edge& a, const Edge& b) {
        return make_pair(a.capacity, a.toll) > make_pair(b.capacity, b.toll);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> enjoyment(N);
    for (int i = 0; i < N; i++) {
        cin >> enjoyment[i];
    }

    map<pair<int, int>, int> tollmap;
    vector<vector<int>> tree(N);
    vector<Edge> edges(N - 1);
    for (auto& [capacity, toll, u, v] : edges) {
        cin >> u >> v >> capacity >> toll, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        tollmap[{u, v}] = tollmap[{v, u}] = toll;
    }
    sort(begin(edges), end(edges));

    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q].capacity >> queries[q].u, queries[q].u--;
        queries[q].id = q;
    }
    sort(begin(queries), end(queries));

    centroid_any_sparse_table<int, function<int(int, int)>> ctd(
        tree, [&](int) { return 0; },
        [&](int toll, int u, int v) {
            return max(toll, tollmap[{u, v}]);
        },
        [&](int a, int b) { return max(a, b); });

    // dsu tree
    vector<int> dsu_root(2 * N);
    vector<int> dsu_center(2 * N);
    vector<pair<int, int>> dsu_val(2 * N, {0, 0});
    int R = N;

    iota(begin(dsu_root), end(dsu_root), 0);
    for (int i = 0; i < N; i++) {
        dsu_val[i] = {enjoyment[i], 0};
    }

    auto find = y_combinator([&](auto self, int u) -> int {
        int p = dsu_root[u];
        while (dsu_root[p] != p) {
            dsu_root[u] = p = dsu_root[p];
            int v = dsu_center[p];
            auto agg = dsu_val[p];
            if (v != u) {
                agg.second = max(agg.second, ctd.query(u, v));
            }
            dsu_val[u] = max(dsu_val[u], agg);
        }
        return p;
    });

    auto get_val = [&](int u) { return find(u), dsu_val[u]; };

    auto insert_edge = [&](int u, int v, int toll) {
        int a = find(u), b = find(v);
        auto du = dsu_val[u];
        auto dv = dsu_val[v];
        du.second = max(du.second, toll);
        dv.second = max(dv.second, toll);
        dsu_val[a] = max(dsu_val[a], dv);
        dsu_val[b] = max(dsu_val[b], du);
        dsu_val[R] = max(dsu_val[a], dsu_val[b]);
        dsu_center[R] = u;
        dsu_root[a] = dsu_root[b] = R++;
    };

    int i = 0;
    vector<pair<int, int>> ans(Q);

    for (auto& [id, s, capacity] : queries) {
        while (i < N - 1 && edges[i].capacity >= capacity) {
            auto [cap, toll, u, v] = edges[i++];
            insert_edge(u, v, toll);
        }
        ans[id] = get_val(s);
    }

    for (int q = 0; q < Q; q++) {
        auto [enjoy, toll] = ans[q];
        cout << enjoy << ' ' << toll << '\n';
    }

    return 0;
}
