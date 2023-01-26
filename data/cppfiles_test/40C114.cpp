#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void _debug() { std::cerr << std::endl; }
template <typename T, typename... U>
void _debug(T t, U... args) {
  std::cerr << " " << t;
  _debug(args...);
}
const int maxn = 1e6 + 10;
struct Dsu {
  vector<int> f;
  int n;
  Dsu(int n) : n(n) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
  }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      f[x] = y;
      return true;
    }
    return false;
  }
};
vector<int> g[maxn];
vector<vector<int>> path;
int n, m;
int dep[maxn], fa[maxn], cnt[maxn], ans = 0;
void dfs(int p, int fa) {
  dep[p] = dep[fa] + 1;
  ::fa[p] = fa;
  for (int i : g[p]) {
    if (i == fa) continue;
    dfs(i, p);
  }
}
int lca(int u, int v) {
  vector<int> p, q;
  bool rev = 0;
  if (dep[u] < dep[v]) swap(u, v), rev = 1;
  while (dep[u] > dep[v]) {
    p.push_back(u);
    cnt[u] ^= 1;
    u = fa[u];
  }
  while (u != v) {
    cnt[u] ^= 1, cnt[v] ^= 1;
    p.push_back(u);
    q.push_back(v);
    u = fa[u];
    v = fa[v];
  }
  p.push_back(u);
  reverse(q.begin(), q.end());
  for (int i : q) p.push_back(i);
  if (rev) reverse(p.begin(), p.end());
  path.emplace_back(p);
  return u;
}
int dfs2(int p, int fa) {
  int c = 0;
  for (int i : g[p]) {
    if (i == fa) continue;
    c += dfs2(i, p);
  }
  ans += c / 2;
  if (cnt[p])
    return 1;
  else {
    if (c & 1) ans++;
    return 0;
  }
}
int main() {
  cin >> n >> m;
  Dsu dsu(n + 10);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (dsu.unite(u, v)) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  dfs(1, 0);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    lca(a, b);
  }
  bool ok = 1;
  for (int i = 1; i <= n; i++) {
    ok &= cnt[i] % 2 == 0;
  }
  if (ok) {
    puts("YES");
    for (auto &vec : path) {
      printf("%d\n", (int)vec.size());
      for (int i : vec) printf("%d ", i);
      puts("");
    }
    return 0;
  }
  puts("NO");
  printf("%d\n", ans + dfs2(1, 0));
}
