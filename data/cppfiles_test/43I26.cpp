#include <bits/stdc++.h>
using std::function;
using std::pair;
using std::tuple;
using std::vector;
const int N = 2e5 + 5;
const int logN = 18;
int n, q;
int e[N];
pair<int, int> ans[N];
vector<tuple<int, int, int>> edge;
vector<tuple<int, int, int>> query;
vector<pair<int, int>> adj[N];
struct {
  int lg2[N], dep[N];
  int max[N][logN], fa[N][logN];
  void init() {
    function<void(int, int, int)> dfs = [&](int x, int f, int t) {
      *fa[x] = f, *max[x] = t;
      dep[x] = dep[f] + 1;
      for (int j = 1; j < logN; j++) {
        fa[x][j] = fa[fa[x][j - 1]][j - 1];
        max[x][j] = std::max(max[x][j - 1], max[fa[x][j - 1]][j - 1]);
      }
      for (auto y : adj[x])
        if (y.first != f) dfs(y.first, x, y.second);
    };
    dfs(1, 0, 0);
    lg2[0] = -1;
    for (int i = 1; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
  }
  inline int operator()(int x, int y) {
    int ans = 0;
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int j = logN - 1; j >= 0; j--)
      if (dep[fa[x][j]] >= dep[y]) ans = std::max(ans, max[x][j]), x = fa[x][j];
    if (x == y) return ans;
    for (int j = logN - 1; j >= 0; j--)
      if (fa[x][j] != fa[y][j]) {
        ans = std::max({ans, max[x][j], max[y][j]});
        x = fa[x][j], y = fa[y][j];
      }
    return std::max({ans, max[x][0], max[y][0]});
  }
} path_max;
int uset[N];
int find(int x) { return x == uset[x] ? x : uset[x] = find(uset[x]); }
pair<int, int> max_e[N];
int max_t[N];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) std::cin >> e[i];
  for (int i = 1; i < n; i++) {
    int a, b, c, t;
    std::cin >> a >> b >> c >> t;
    edge.emplace_back(c, a, b);
    adj[a].emplace_back(b, t);
    adj[b].emplace_back(a, t);
  }
  path_max.init();
  std::sort((edge).begin(), (edge).end());
  std::reverse((edge).begin(), (edge).end());
  for (int i = 1; i <= q; i++) {
    int v, x;
    std::cin >> v >> x;
    query.emplace_back(v, x, i);
  }
  std::sort((query).begin(), (query).end());
  std::reverse((query).begin(), (query).end());
  for (int i = 1; i <= n; i++) {
    max_e[i] = std::make_pair(e[i], i);
    max_t[i] = 0;
  }
  auto it = query.begin();
  for (int i = 1; i <= n; i++) uset[i] = i;
  for (; it != query.end() && std::get<0>(*it) > std::get<0>(edge.front());
       ++it)
    ans[std::get<2>(*it)] = std::make_pair(e[std::get<1>(*it)], 0);
  for (auto et : edge) {
    int u, v, c;
    std::tie(c, u, v) = et;
    u = find(u), v = find(v);
    if (max_e[u].first != max_e[v].first)
      max_t[u] = max_e[u].first > max_e[v].first ? max_t[u] : max_t[v];
    else
      max_t[u] = std::max(
          {max_t[u], max_t[v], path_max(max_e[u].second, max_e[v].second)});
    max_e[u] = std::max(max_e[u], max_e[v]);
    uset[v] = u;
    for (; it != query.end() && std::get<0>(*it) >= c; ++it) {
      int v, x, id;
      std::tie(v, x, id) = *it;
      int fx = find(x);
      ans[id].first = max_e[fx].first;
      ans[id].second = std::max(max_t[fx], path_max(x, max_e[fx].second));
    }
  }
  for (int i = 1; i <= q; i++)
    std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
  return 0;
}
