#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 20;
const int L = 18;
vector<pair<int, int>> g[N];
int xr[N], sz[N];
int up[N][L + 1], tin[N], tout[N], timer;
int pr[N];
int root(int v) {
  if (pr[v] == v) return v;
  return pr[v] = root(pr[v]);
}
bool merge(int u, int v) {
  u = root(u);
  v = root(v);
  if (u == v) return false;
  pr[u] = v;
  return true;
}
void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = (p == -1 ? v : p);
  for (int i = 1; i <= L; i++) up[v][i] = up[up[v][i - 1]][i - 1];
  sz[v] = 1;
  for (auto [to, x] : g[v]) {
    if (to == p) continue;
    xr[to] = xr[v] ^ x;
    dfs(to, v);
    sz[v] += sz[to];
  }
  tout[v] = ++timer;
}
bool upper(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int getLCA(int u, int v) {
  if (upper(u, v)) return u;
  if (upper(v, u)) return v;
  for (int i = L; i >= 0; i--)
    if (!upper(up[v][i], u)) v = up[v][i];
  return up[v][0];
}
int chain[N], pos[N], start[N], curp, curch;
void hld(int v, int p) {
  pos[v] = curp++;
  int big = -1;
  for (auto [to, x] : g[v]) {
    if (to == p) continue;
    if (big == -1 || sz[to] > sz[big]) big = to;
  }
  if (big == -1) return;
  chain[big] = chain[v];
  hld(big, v);
  for (auto [to, x] : g[v]) {
    if (to == p || to == big) continue;
    chain[to] = ++curch;
    start[curch] = to;
    hld(to, v);
  }
}
bool t[4 * N], b[4 * N];
bool get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (t[v]) return true;
  if (tl == l && tr == r) {
    return b[v];
  }
  int tm = (tl + tr) / 2;
  return (get(v * 2, tl, tm, l, min(r, tm)) ||
          get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void upd(int v, int tl, int tr, int l, int r) {
  if (l > r) return;
  if (tl == l && tr == r) {
    t[v] = b[v] = true;
    return;
  }
  b[v] = true;
  int tm = (tl + tr) / 2;
  upd(v * 2, tl, tm, l, min(r, tm));
  upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
bool query(int u, int v) {
  int z = getLCA(u, v);
  bool mark = false;
  while (!mark) {
    if (chain[u] == chain[z]) {
      mark |= get(1, 0, N - 1, pos[z] + 1, pos[u]);
      break;
    }
    mark |= get(1, 0, N - 1, pos[start[chain[u]]], pos[u]);
    u = up[start[chain[u]]][0];
  }
  while (!mark) {
    if (chain[v] == chain[z]) {
      mark |= get(1, 0, N - 1, pos[z] + 1, pos[v]);
      break;
    }
    mark |= get(1, 0, N - 1, pos[start[chain[v]]], pos[v]);
    v = up[start[chain[v]]][0];
  }
  return mark;
}
void upd(int u, int v) {
  int z = getLCA(u, v);
  while (true) {
    if (chain[u] == chain[z]) {
      upd(1, 0, N - 1, pos[z] + 1, pos[u]);
      break;
    }
    upd(1, 0, N - 1, pos[start[chain[u]]], pos[u]);
    u = up[start[chain[u]]][0];
  }
  while (true) {
    if (chain[v] == chain[z]) {
      upd(1, 0, N - 1, pos[z] + 1, pos[v]);
      break;
    }
    upd(1, 0, N - 1, pos[start[chain[v]]], pos[v]);
    v = up[start[chain[v]]][0];
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int>> s;
  iota(pr, pr + n, 0);
  for (int i = 0; i < q; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    --u;
    --v;
    if (merge(u, v)) {
      g[u].push_back({v, x});
      g[v].push_back({u, x});
      x = -1;
    }
    s.push_back(make_tuple(u, v, x));
  }
  dfs(0, -1);
  hld(0, -1);
  for (auto [u, v, x] : s) {
    if (x == -1) {
      cout << "YES\n";
      continue;
    }
    if ((xr[u] ^ xr[v] ^ x) != 1 || query(u, v)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    upd(u, v);
  }
}
