#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 500;
bool mk[N * 2];
int xr[N], tim;
int t[2 * N], up[N][19], tin[N], tout[N], pr[N];
vector<pair<int, int> > g[N];
vector<pair<pair<int, int>, int> > qr;
void upd(int v, int val) {
  for (; v < N; v = (v | (v + 1))) t[v] += val;
}
int get(int v) {
  int ret = 0;
  for (; v >= 0; v = (v & (v + 1)) - 1) ret += t[v];
  return ret;
}
int f(int v) { return (pr[v] == v ? v : pr[v] = f(pr[v])); }
void link(int v, int u) { pr[u] = v; }
bool ispr(int v, int u) { return (tin[v] <= tin[u] && tout[v] >= tout[u]); }
int lca(int v, int u) {
  if (ispr(v, u)) {
    return v;
  }
  if (ispr(u, v)) {
    return u;
  }
  for (int st = 18; st >= 0; st--) {
    if (!ispr(up[v][st], u)) {
      v = up[v][st];
    }
  }
  return up[v][0];
}
void dfs(int v, int pr) {
  tin[v] = tim++;
  up[v][0] = pr;
  for (auto u : g[v]) {
    if (u.first == pr) {
      continue;
    }
    xr[u.first] = xr[v] ^ u.second;
    dfs(u.first, v);
  }
  tout[v] = tim++;
}
void upd_path(int v, int u, int lc) {
  while (v != lc) {
    upd(tin[v], 1);
    upd(tout[v], -1);
    v = up[v][0];
  }
  while (u != lc) {
    upd(tin[u], 1);
    upd(tout[u], -1);
    u = up[u][0];
  }
}
bool get_path(int v, int u, int lc) {
  return (get(tin[v]) + get(tin[u]) - 2 * get(tin[lc]));
}
int main() {
  istream::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(9);
  cout << fixed;
  int n, m, v, u, x;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    pr[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> v >> u >> x;
    qr.push_back({{v, u}, x});
    if (f(v) == f(u)) {
      continue;
    } else {
      link(f(v), f(u));
      mk[i - 1] = 1;
      g[v].push_back({u, x});
      g[u].push_back({v, x});
    }
  }
  tin[0] = tim++;
  xr[1] = 0;
  dfs(1, 0);
  tout[0] = tim++;
  for (int st = 1; st < 19; st++) {
    for (int i = 1; i <= n; i++) {
      up[i][st] = up[up[i][st - 1]][st - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    if (mk[i]) {
      cout << "YES" << '\n';
      continue;
    }
    int v = qr[i].first.first;
    int u = qr[i].first.second;
    int x = qr[i].second;
    int lc = lca(v, u);
    if ((xr[v] ^ xr[u] ^ x) == 0 || get_path(v, u, lc)) {
      cout << "NO" << '\n';
    } else {
      upd_path(v, u, lc);
      cout << "YES" << '\n';
    }
  }
}
