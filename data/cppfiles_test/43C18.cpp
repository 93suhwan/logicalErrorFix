#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct node {
  int x, y, w, t;
  bool operator<(const node& a) const { return w > a.w; }
} e[maxn];
int ans[maxn][2];
vector<pair<int, int> > g[maxn];
int a[maxn];
int n, q;
int f[maxn][20], mx[maxn][20];
int dep[maxn];
void dfs(int u, int pa) {
  for (auto p : g[u]) {
    int v, w;
    tie(v, w) = p;
    if (v == pa) continue;
    mx[v][0] = w;
    f[v][0] = u;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}
int get_mx(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int d = dep[u] - dep[v];
  int res = 0;
  for (int i = 0; i < 20; ++i)
    if (d >> i & 1) res = max(res, mx[u][i]), u = f[u][i];
  if (u == v) return res;
  for (int i = 19; i >= 0; --i) {
    if (f[u][i] ^ f[v][i])
      res = max({res, mx[u][i], mx[v][i]}), u = f[u][i], v = f[v][i];
  }
  res = max({res, mx[u][0], mx[v][0]});
  return res;
}
int x[maxn], y[maxn], fuck[maxn];
int fa[maxn];
int fnd(int x) { return x == fa[x] ? x : fa[x] = fnd(fa[x]); }
void link(int u, int v) {
  u = fnd(u);
  v = fnd(v);
  if (u == v) {
    assert(0);
  }
  if (a[u] < a[v]) swap(u, v);
  if (a[u] == a[v]) fuck[u] = max({fuck[u], get_mx(u, v), fuck[v]});
  fa[v] = u;
  return;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i < n + 1; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int u, v, w, t;
    scanf("%d%d%d%d", &u, &v, &w, &t);
    e[i] = (node){u, v, w, t};
    g[u].push_back(pair<int, int>(v, t));
    g[v].push_back(pair<int, int>(u, t));
  }
  dfs(1, 0);
  for (int j = 1; j < 20; ++j)
    for (int i = 1; i < n + 1; ++i)
      f[i][j] = f[f[i][j - 1]][j - 1],
      mx[i][j] = max(mx[i][j - 1], mx[f[i][j - 1]][j - 1]);
  sort(e + 1, e + n);
  vector<int> ask;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &y[i], &x[i]);
    ask.push_back(i);
  }
  sort(ask.begin(), ask.end(), [&](int u, int v) { return y[u] > y[v]; });
  for (int i = 1; i < n + 1; ++i) fa[i] = i, fuck[i] = 0;
  int p = 1;
  for (int i = 0; i < q; ++i) {
    int o = ask[i];
    while (p < n && e[p].w >= y[o]) link(e[p].x, e[p].y), p++;
    int rt = fnd(x[o]);
    ans[o][0] = a[rt];
    ans[o][1] = max(fuck[rt], get_mx(x[o], rt));
  }
  for (int i = 0; i < q; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
