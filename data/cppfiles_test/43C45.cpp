#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
template <int T>
using A = array<int, T>;
const int maxn = 2e5;
const int maxlg = 17;
int n, m, a[maxn + 5], val[maxn + 5], top[maxn + 5], vmx[maxn + 5],
    dep[maxn + 5], lg[maxn + 5];
int fa[maxn + 5][maxlg + 1], mx[maxn + 5][maxlg + 1];
vector<A<2>> g[maxn + 5];
A<4> e[maxn + 5];
A<3> q[maxn + 5];
A<2> ans[maxn + 5];
set<int> s;
namespace dsu {
int fa[maxn + 5];
vector<int> g[maxn + 5];
void clear() {
  for (int i = (1); i <= int(n); i++) fa[i] = i;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
}  // namespace dsu
using dsu::find;
void dfs(int u, int par) {
  for (int i = (1); i <= int(maxlg); i++)
    fa[u][i] = fa[fa[u][i - 1]][i - 1],
    mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
  for (auto v : g[u])
    if (v[0] != par) {
      dep[v[0]] = dep[u] + 1;
      fa[v[0]][0] = u;
      mx[v[0]][0] = v[1];
      dfs(v[0], u);
    }
}
int qrymx(int u, int v) {
  int d = dep[u] - dep[v], res = 0;
  for (; d; d ^= ((d) & (-d)))
    chkmx(res, mx[u][lg[((d) & (-d))]]), u = fa[u][lg[((d) & (-d))]];
  return res;
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int d = dep[u] - dep[v];
  for (; d; d ^= ((d) & (-d))) u = fa[u][lg[((d) & (-d))]];
  if (u == v) return u;
  for (int i = (maxlg); i >= int(0); i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
A<2> ask(int u) {
  int x = top[find(u)], y = lca(u, x);
  return {vmx[find(u)], max({qrymx(x, y), qrymx(u, y), val[find(u)]})};
}
int main() {
  cin >> n >> m;
  for (int i = (1); i <= int(n); i++) cin >> a[i];
  for (int i = (1); i <= int(n - 1); i++)
    cin >> e[i][0] >> e[i][1] >> e[i][2] >> e[i][3],
        g[e[i][0]].push_back({e[i][1], e[i][3]}),
        g[e[i][1]].push_back({e[i][0], e[i][3]});
  for (int i = (1); i <= int(m); i++) cin >> q[i][0] >> q[i][1], q[i][2] = i;
  dsu::clear();
  sort(e + 1, e + n, [&](A<4> x, A<4> y) { return x[2] > y[2]; });
  sort(q + 1, q + m + 1, [&](A<3> x, A<3> y) { return x[0] > y[0]; });
  int p = 1;
  dfs(1, 1);
  for (int i = (1); i <= int(n); i++) top[i] = i, vmx[i] = a[i];
  for (int i = (0); i <= int(maxlg); i++) lg[1 << i] = i;
  for (int i = (1); i <= int(n - 1); i++) {
    while (p <= m && q[p][0] > e[i][2]) ans[q[p][2]] = ask(q[p][1]), p++;
    if (dep[e[i][0]] > dep[e[i][1]]) swap(e[i][0], e[i][1]);
    int fx = find(e[i][0]), fy = find(e[i][1]);
    assert(e[i][1] == fy);
    dsu::fa[fy] = fx;
    if (vmx[fx] < vmx[fy]) {
      val[fx] = val[fy];
      top[fx] = top[fy];
      vmx[fx] = vmx[fy];
    } else if (vmx[fx] > vmx[fy]) {
      ;
    } else {
      int x = lca(top[fx], top[fy]);
      chkmx(val[fx], max({val[fy], qrymx(top[fx], x), qrymx(top[fy], x)}));
      if (x != top[fx]) top[fx] = x;
    }
  }
  while (p <= m) ans[q[p][2]] = ask(q[p][1]), p++;
  for (int i = (1); i <= int(m); i++)
    cout << ans[i][0] << ' ' << ans[i][1] << '\n';
  return 0;
}
