#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ull = unsigned long long;
const int N = 1e5 + 5, LG = 17, MOD = 1e9 + 7;
const long double PI = acos(-1);
int n, m;
int a[N];
vector<int> adj[N];
int pa[N][LG], lvl[N];
int in[N], out[N], timer;
long long t[N << 2], lz[N << 2];
void dfs(int u, int p) {
  in[u] = ++timer;
  for (int k = 1; k < LG; k++) pa[u][k] = pa[pa[u][k - 1]][k - 1];
  for (auto v : adj[u])
    if (v != p) {
      lvl[v] = lvl[u] + 1;
      pa[v][0] = u;
      dfs(v, u);
    }
  out[u] = timer;
}
int LCA(int u, int v) {
  if (lvl[u] > lvl[v]) swap(u, v);
  int d = lvl[v] - lvl[u];
  for (int k = 0; k < LG; k++)
    if (d >> k & 1) v = pa[v][k];
  if (u == v) return u;
  for (int i = LG - 1; i >= 0; --i)
    if (pa[u][i] != pa[v][i]) {
      u = pa[u][i];
      v = pa[v][i];
    }
  return pa[u][0];
}
void push(int node, int s, int e) {
  t[node] += lz[node];
  if (s != e) {
    lz[node << 1] += lz[node];
    lz[node << 1 | 1] += lz[node];
  }
  lz[node] = 0;
}
void update(int node, int s, int e, int l, int r, int val) {
  push(node, s, e);
  if (r < s || e < l) return;
  if (l <= s && e <= r) {
    lz[node] += val;
    push(node, s, e);
    return;
  }
  int md = (s + e) >> 1;
  update(node << 1, s, md, l, r, val);
  update(node << 1 | 1, md + 1, e, l, r, val);
  t[node] = t[node << 1] + t[node << 1 | 1];
}
int query(int node, int s, int e, int index) {
  push(node, s, e);
  if (s == e) return t[node];
  int md = (s + e) >> 1;
  if (index <= md) return query(node << 1, s, md, index);
  return query(node << 1 | 1, md + 1, e, index);
}
void doWork() {
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  for (int i = 1; i < n + 1; i++) update(1, 1, n, in[i], out[i], a[i]);
  while (m--) {
    int tp, x, y;
    cin >> tp >> x >> y;
    y = abs(y);
    if (tp == 1) {
      update(1, 1, n, in[x], out[x], y - a[x]);
      a[x] = y;
    } else {
      long long ans = query(1, 1, n, in[x]) * 2;
      ans += query(1, 1, n, in[y]) * 2;
      int L = LCA(x, y);
      ans -= query(1, 1, n, in[L]) * 2;
      if (L != 1) ans -= query(1, 1, n, in[pa[L][0]]) * 2;
      ans -= a[x];
      ans -= a[y];
      cout << ans << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    doWork();
  }
  return 0;
}
