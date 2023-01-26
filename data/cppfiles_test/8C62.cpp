#include <bits/stdc++.h>
using namespace std;
template <typename T>
void dbn(T a) {
  cerr << "#0 = " << a << '\n';
}
template <typename T, typename... Rest>
void dbn(T a, Rest... rest) {
  dbn(rest...);
  cerr << '#' << sizeof...(rest) << " = " << a << '\n';
}
const int MAX_N = 100002;
const int MAGIC = 300;
const int LG_N = 17;
int n, nQueries, timer, buffer_value[MAX_N], a[MAX_N], tin[MAX_N], tout[MAX_N];
int64_t f[MAX_N];
int p[MAX_N][LG_N + 2];
bool in_buffer[MAX_N];
vector<int> g[MAX_N];
vector<int> buffer;
int64_t calc_old_weight(int u, int v) {
  return max(abs(a[u] + a[v]), abs(a[u] - a[v]));
}
int64_t calc_new_weight(int u, int v) {
  int x = (in_buffer[u] ? buffer_value[u] : a[u]);
  int y = (in_buffer[v] ? buffer_value[v] : a[v]);
  return max(abs(x + y), abs(x - y));
}
void fix_root(int u) {
  tin[u] = ++timer;
  for (auto v : g[u]) {
    if (v != p[u][0]) {
      p[v][0] = u;
      f[v] = f[u] + calc_old_weight(u, v);
      fix_root(v);
    }
  }
  tout[u] = ++timer;
}
void build_lca() {
  for (int i = 1; i <= LG_N; ++i) {
    for (int u = 1; u <= n; ++u) {
      p[u][i] = p[p[u][i - 1]][i - 1];
    }
  }
  for (int u = 2; u <= n; ++u)
    g[u].erase(find(g[u].begin(), g[u].end(), p[u][0]));
}
bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = LG_N; i >= 0; --i) {
    if (p[u][i] != 0 && !is_ancestor(p[u][i], v)) u = p[u][i];
  }
  return p[u][0];
}
void add_update_query(int u, int c) {
  if (!in_buffer[u]) buffer.push_back(u);
  in_buffer[u] = true;
  buffer_value[u] = c;
  if (buffer.size() > MAGIC) {
    for (auto v : buffer) {
      in_buffer[v] = false;
      a[v] = buffer_value[v];
    }
    buffer.clear();
    fix_root(1);
  }
}
int bisect(int anc, int des) {
  int l = 0, r = (int)g[anc].size() - 1;
  for (int mid = (l + r) / 2; mid != l && mid != r; mid = (l + r) / 2) {
    int u = g[anc][mid];
    if (tout[u] < tout[des])
      l = mid;
    else
      r = mid;
  }
  for (int mid = l; mid <= r; ++mid) {
    int u = g[anc][mid];
    if (is_ancestor(u, des)) return u;
  }
  assert(0);
}
bool onPath(int u, int v, int anc, int w) {
  if (!is_ancestor(anc, w)) return false;
  return is_ancestor(w, u) || is_ancestor(w, v);
}
int64_t query(int u, int v) {
  int anc = lca(u, v);
  int64_t res = f[u] + f[v] - 2 * f[anc];
  for (auto w : buffer) {
    if (!onPath(u, v, anc, w)) continue;
    if (onPath(u, v, anc, p[w][0]) && !in_buffer[p[w][0]])
      res = res - calc_old_weight(w, p[w][0]) + calc_new_weight(w, p[w][0]);
    if (u != w && is_ancestor(w, u)) {
      int t = bisect(w, u);
      res = res - calc_old_weight(w, t) + calc_new_weight(w, t);
    }
    if (v != w && is_ancestor(w, v)) {
      int t = bisect(w, v);
      res = res - calc_old_weight(w, t) + calc_new_weight(w, t);
    }
  }
  return res;
}
int main() {
  cin >> n >> nQueries;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fix_root(1);
  build_lca();
  while (nQueries--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1)
      add_update_query(u, v);
    else {
      cout << query(u, v) << '\n';
    }
  }
}
