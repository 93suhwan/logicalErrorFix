#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const int max_n = 1e5 + 10, inf = 1000111222;
const int max_lev = 17;
class tree {
 public:
  int tin[max_n], tout[max_n];
  int h[max_n];
  int p[max_lev][max_n];
  void init(int n, vector<int> g[], int root = 0) {
    curt = -1;
    for (int i = 0; i < max_lev; ++i) {
      p[i][root] = root;
    }
    dfs(root, g);
    get_all_p(n);
  }
  bool is_ancestor(int u, int v) const {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  }
  int lca(int u, int v) const {
    if (is_ancestor(u, v)) {
      return u;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
      if (!is_ancestor(p[i][u], v)) {
        u = p[i][u];
      }
    }
    return p[0][u];
  }
  int get_dist(int u, int v) const {
    const int lc = lca(u, v);
    return h[u] + h[v] - 2 * h[lc];
  }
  int get_up(int v, int dist) const {
    for (int i = max_lev - 1; i >= 0; --i) {
      if (get_bit(dist, i)) {
        v = p[i][v];
      }
    }
    return v;
  }
  bool is_on_way(int u, int v, int lca, int q) {
    return is_ancestor(lca, q) && (is_ancestor(q, u) || is_ancestor(q, v));
  }

 protected:
  void dfs(int v, vector<int> g[]) {
    tin[v] = ++curt;
    for (int to : g[v]) {
      if (to == p[0][v]) {
        continue;
      }
      p[0][to] = v;
      h[to] = h[v] + 1;
      dfs(to, g);
    }
    tout[v] = curt;
  }
  void get_all_p(int n) {
    for (int lev = 1; lev < max_lev; ++lev) {
      for (int i = 0; i < n; ++i) {
        p[lev][i] = p[lev - 1][p[lev - 1][i]];
      }
    }
  }
  static bool get_bit(int mask, int pos) { return (mask >> pos) & 1; }
  int curt;
};
class heavy_light_tree : public tree {
 public:
  int up[max_n], sz[max_n];
  vector<int> order;
  void init(int n, vector<int> g[], int root = 0) {
    curt = -1;
    for (int i = 0; i < max_lev; ++i) {
      p[i][root] = root;
    }
    reorder_subtrees(root, -1, g);
    up[root] = root;
    dfs(root, g);
    get_all_p(n);
  }
  template <bool lca_inclusive, typename Callback>
  void decompose_on_paths(int v1, int v2, Callback &callback) const {
    const int lc = lca(v1, v2);
    vertical_decompose_on_paths<lca_inclusive>(v1, lc, callback);
    vertical_decompose_on_paths<false>(v2, lc, callback);
  }
  template <bool lca_inclusive>
  vector<pair<int, int>> decompose_on_paths(int v1, int v2) const {
    vector<pair<int, int>> res;
    auto callback = [&res](int l, int r) { res.emplace_back(l, r); };
    decompose_on_paths<lca_inclusive>(v1, v2, callback);
    return res;
  }

 private:
  template <bool parent_inclusive, typename Callback>
  void vertical_decompose_on_paths(int v, int parent,
                                   Callback &callback) const {
    while (true) {
      if (is_ancestor(up[v], parent)) {
        const int l = tin[parent] + !parent_inclusive, r = tin[v];
        if (l <= r) {
          callback(l, r);
        }
        return;
      }
      callback(tin[up[v]], tin[v]);
      v = p[0][up[v]];
    }
  }
  void reorder_subtrees(int v, int p, vector<int> g[]) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
      if (g[v][i] == p) {
        swap(g[v][i], g[v].back());
        g[v].pop_back();
        break;
      }
    }
    for (int to : g[v]) {
      reorder_subtrees(to, v, g);
      sz[v] += sz[to];
    }
    for (int i = 1; i < g[v].size(); ++i) {
      if (sz[g[v][i]] > sz[g[v][0]]) {
        swap(g[v][i], g[v][0]);
      }
    }
  }
  void dfs(int v, vector<int> g[]) {
    order.push_back(v);
    tin[v] = ++curt;
    sz[v] = 1;
    for (int to : g[v]) {
      if (to == p[0][v]) {
        continue;
      }
      up[to] = to;
      if (to == g[v][0]) {
        up[to] = up[v];
      }
      p[0][to] = v;
      h[to] = h[v] + 1;
      dfs(to, g);
      sz[v] += sz[to];
    }
    tout[v] = curt;
  }
};
vector<int> build_virtual_tree(const tree &t, vector<int> vs, vector<int> g[]) {
  auto cmp_by_tin = [&t](int a, int b) { return t.tin[a] < t.tin[b]; };
  sort(vs.begin(), vs.end(), cmp_by_tin);
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  for (int i = 0, sz = vs.size(); i + 1 < sz; ++i) {
    vs.push_back(t.lca(vs[i], vs[i + 1]));
  }
  sort(vs.begin(), vs.end(), cmp_by_tin);
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  const int n = vs.size();
  for (int i = 0; i < n; ++i) {
    g[vs[i]].clear();
  }
  vector<int> st;
  for (int v : vs) {
    while (!st.empty() && !t.is_ancestor(st.back(), v)) {
      st.pop_back();
    }
    if (!st.empty()) {
      g[st.back()].push_back(v);
      g[v].push_back(st.back());
    }
    st.push_back(v);
  }
  return vs;
}
int a[max_n];
vector<int> reb[max_n];
const int magic = 130;
tree T;
long long first[max_n];
void F_upd(int pos, long long val) {
  for (int i = pos; i < max_n; i |= i + 1) {
    first[i] += val;
  }
}
long long F_get(int pos) {
  long long res = 0;
  for (int i = pos; i >= 0; i &= i + 1, i--) {
    res += first[i];
  }
  return res;
}
void F_upd_on_segment(int l, int r, int value) {
  F_upd(l, value);
  F_upd(r + 1, -value);
}
long long F_get_in_point(int pos) { return F_get(pos); }
const bool debug = 0;
int main() {
  int n, q;
  if (debug) {
    n = 1e5;
    q = 1e5;
  } else {
    scanf("%d%d", &n, &q);
  }
  for (int i = 0; i < n; i++) {
    if (debug) {
      a[i] = rand() % 1000000;
    } else {
      scanf("%d", &a[i]);
    }
  }
  vector<pair<int, int>> all_edges;
  for (int i = 1; i < n; i++) {
    int u, v;
    if (debug) {
      u = i;
      v = i + 1;
    } else {
      scanf("%d%d", &u, &v);
    }
    u--;
    v--;
    reb[u].push_back(v);
    reb[v].push_back(u);
    all_edges.push_back(make_pair(u, v));
  }
  vector<pair<int, int>> heavy_edges;
  for (auto i : all_edges) {
    if ((int)(reb[i.first].size()) > magic ||
        (int)(reb[i.second].size()) > magic) {
      heavy_edges.push_back(i);
    }
  }
  auto get_value = [&](int u, int v) { return max(abs(u + v), abs(u - v)); };
  T.init(n, reb, 0);
  for (int u = 0; u < n; u++) {
    for (auto v : reb[u]) {
      if ((int)(reb[u].size()) <= magic && (int)(reb[v].size()) <= magic) {
        int uu = u;
        int vv = v;
        if (T.is_ancestor(uu, vv)) {
          F_upd_on_segment(T.tin[vv], T.tout[vv], +get_value(a[uu], a[vv]));
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int type;
    if (debug) {
      type = 1 + i % 2;
    } else {
      scanf("%d", &type);
    }
    if (type == 1) {
      int u, c;
      if (debug) {
        u = rand() % n + 1;
        c = rand() % 1000000;
      } else {
        scanf("%d%d", &u, &c);
      }
      u--;
      if ((int)(reb[u].size()) <= magic) {
        for (auto v : reb[u]) {
          if ((int)(reb[v].size()) <= magic) {
            int uu = u;
            int vv = v;
            if (!T.is_ancestor(uu, vv)) {
              swap(uu, vv);
            }
            F_upd_on_segment(T.tin[vv], T.tout[vv],
                             +get_value(c, a[vv]) - get_value(a[uu], a[vv]));
          }
        }
      }
      a[u] = c;
    } else {
      int u, v;
      if (debug) {
        u = rand() % n + 1;
        v = rand() % n + 1;
      } else {
        scanf("%d%d", &u, &v);
      }
      u--;
      v--;
      int lca = T.lca(u, v);
      long long ans = 0;
      ans += F_get_in_point(T.tin[u]);
      ans += F_get_in_point(T.tin[v]);
      ans -= 2 * F_get_in_point(T.tin[lca]);
      for (auto q : heavy_edges) {
        if (T.is_on_way(u, v, lca, q.first) &&
            T.is_on_way(u, v, lca, q.second)) {
          ans += get_value(a[q.first], a[q.second]);
        }
      }
      cout << ans << "\n";
    }
  }
}
