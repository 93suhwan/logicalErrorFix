#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> E;
vector<int> fa, dis;
int find(int x) {
  if (x != fa[x]) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}
inline void merge(int x, int y) {
  x = find(x);
  y = find(y);
  fa[x] = y;
}
void dfs(int u, int fa) {
  for (auto i : E[u]) {
    auto v = i.first, w = i.second;
    if (v == fa) continue;
    if (w != -1) {
      cout << u << " " << v << " " << w << "\n";
    } else {
      cout << u << " " << v << " " << int(dis[u] ^ dis[v]) << "\n";
    }
    dfs(v, u);
  }
}
void solve() {
  int n, q;
  cin >> n >> q;
  E.clear(), fa.clear(), dis.clear();
  E.resize(n + 1), fa.resize(2 * n + 1), dis.resize(n + 1);
  iota(fa.begin(), fa.end(), 0);
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    E[u].push_back({v, w});
    E[v].push_back({u, w});
    if (w != -1) {
      w = __builtin_popcount(w) % 2;
      if (w % 2) {
        merge(u, v + n), merge(u + n, v);
      } else {
        merge(u, v), merge(u + n, v + n);
      }
    }
  }
  for (int i = 1, u, v, w; i <= q; ++i) {
    cin >> u >> v >> w;
    if (w % 2) {
      merge(u, v + n), merge(u + n, v);
    } else {
      merge(u, v), merge(u + n, v + n);
    }
  }
  for (int i = 1; i <= n; ++i) {
    dis[i] = (find(i) <= n) ? 1 : 0;
    if (find(i) == find(i + n)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  dfs(1, 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
