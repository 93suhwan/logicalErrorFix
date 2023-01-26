#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
int n;
vector<int> a, b, sz, pos, head, depth, p;
vector<vector<int>> g;
int cur_pos = 0;
const int N = 1e5 + 1010;
long long t[4 * N];
void build(int v, int vl, int vr) {
  if (vl == vr) {
    t[v] = {a[vl]};
    return;
  }
  int vm = (vl + vr) / 2;
  build(2 * v + 1, vl, vm);
  build(2 * v + 2, vm + 1, vr);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}
long long query(int v, int vl, int vr, int l, int r) {
  if (r < vl || vr < l) return 0;
  if (vl >= l && vr <= r) return t[v];
  int vm = (vl + vr) / 2;
  return query(2 * v + 1, vl, vm, l, r) + query(2 * v + 2, vm + 1, vr, l, r);
}
void modify(int v, int vl, int vr, int pos, int val) {
  if (vl == vr) {
    t[v] = val;
    return;
  }
  int vm = (vl + vr) / 2;
  if (pos <= vm) {
    modify(2 * v + 1, vl, vm, pos, val);
  } else
    modify(2 * v + 2, vm + 1, vr, pos, val);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}
long long tree_query(int l, int r) { return query(0, 0, n - 1, l, r); }
void dfs_sz(int v, int pr = -1) {
  sz[v] = 1;
  p[v] = pr;
  for (auto &to : g[v])
    if (to != pr) {
      depth[to] = depth[v] + 1;
      dfs_sz(to, v);
      sz[v] += sz[to];
      if (sz[to] > sz[g[v][0]]) swap(g[v][0], to);
    }
}
void dfs_hld(int v) {
  pos[v] = cur_pos++;
  for (auto to : g[v])
    if (to != p[v]) {
      head[to] = (to == g[v][0] ? head[v] : to);
      dfs_hld(to);
    }
}
long long query(int u, int v) {
  long long ans = 0;
  for (; head[u] != head[v]; v = p[head[v]]) {
    if (depth[head[u]] > depth[head[v]]) swap(u, v);
    ans += tree_query(pos[head[v]], pos[v]);
  }
  if (depth[u] > depth[v]) swap(u, v);
  ans += tree_query(pos[u], pos[v]);
  return ans;
}
void tmodify(int v, int x) { modify(0, 0, n - 1, pos[v], x); }
void init() {
  sz.resize(n);
  pos.resize(n);
  head.resize(n);
  depth.resize(n);
  p.resize(n);
  b.resize(n);
  dfs_sz(0);
  dfs_hld(0);
  for (int i = 0; i < n; i++) b[pos[i]] = a[i];
  a = b;
  build(0, 0, n - 1);
}
void solve() {
  int q;
  cin >> n >> q;
  g.resize(n);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  init();
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, c;
      cin >> v >> c;
      v--;
      c = abs(c);
      tmodify(v, c);
    } else {
      int u, v;
      cin >> u >> v;
      u--, v--;
      long long sum = 2 * query(u, v) - query(u, u) - query(v, v);
      cout << sum << '\n';
    }
  }
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
