#include <bits/stdc++.h>
using namespace std;
struct segtree_max_add {
  const pair<int, int> INF = {-1e9, -1e9};
  vector<pair<int, int> > st;
  vector<int> lz;
  int n;
  segtree_max_add(int N) : n(N) {
    st.assign((n << 2) + 5, {0, 0});
    lz.assign((n << 2) + 5, 0);
    build(1, 1, n);
  }
  void build(int id, int l, int r) {
    if (l == r) {
      st[id] = {0, l};
      return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = _max(st[id << 1], st[id << 1 | 1]);
  }
  void push(int id, int l, int r) {
    st[id].first += lz[id];
    if (l != r) {
      lz[id << 1] += lz[id];
      lz[id << 1 | 1] += lz[id];
    }
    lz[id] = 0;
  }
  __attribute__((always_inline)) pair<int, int> _max(pair<int, int> a,
                                                     pair<int, int> b) {
    return (a > b ? a : b);
  }
  void _upd(int u, int v, int val, int id, int l, int r) {
    push(id, l, r);
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      lz[id] = val;
      push(id, l, r);
      return;
    }
    int mid = l + r >> 1;
    _upd(u, v, val, id << 1, l, mid);
    _upd(u, v, val, id << 1 | 1, mid + 1, r);
    st[id] = _max(st[id << 1], st[id << 1 | 1]);
  }
  void upd(int u, int v, int val) { _upd(u, v, val, 1, 1, n); }
  pair<int, int> _query(int u, int v, int id, int l, int r) {
    push(id, l, r);
    if (r < u || l > v) return INF;
    if (l >= u && r <= v) return st[id];
    int mid = l + r >> 1;
    return _max(_query(u, v, id << 1, l, mid),
                _query(u, v, id << 1 | 1, mid + 1, r));
  }
  pair<int, int> query(int u, int v) { return _query(u, v, 1, 1, n); }
};
const int MAXN = 2e5 + 5;
vector<int> path[MAXN];
int dep[MAXN], ver[MAXN];
bool vis[MAXN];
bool leaf[MAXN];
int par[MAXN];
int tin[MAXN], tout[MAXN];
void dfs(int u, int pre = 0) {
  static int timer = 0;
  tin[u] = ++timer;
  ver[timer] = u;
  dep[u] = dep[pre] + 1;
  par[u] = pre;
  leaf[u] = (pre && path[u].size() == 1);
  for (int v : path[u])
    if (v != pre) dfs(v, u);
  tout[u] = timer;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1, u, v; i < n; i++)
    cin >> u >> v, path[u].push_back(v), path[v].push_back(u);
  dfs(1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += leaf[i];
  if (cnt < k) return cout << (n - k) * k << '\n', 0;
  segtree_max_add t(n);
  for (int i = 1; i <= n; i++) {
    if (leaf[i])
      t.upd(tin[i], tin[i], dep[i]);
    else
      t.upd(tin[i], tin[i], -1e9);
  }
  vis[0] = 1;
  cnt = 0;
  int ans = -1e9;
  for (int i = 1; i <= k; i++) {
    auto vv = t.query(1, n);
    int v = ver[vv.second];
    cnt += vv.first - 1;
    t.upd(tin[v], tin[v], -1e9);
    for (; !vis[par[v]]; v = par[v]) vis[v] = 1;
    vis[v] = 1;
    ans = max(ans, (i - (n - cnt - i)) * cnt);
    t.upd(tin[v], tout[v], -1);
  }
  cout << ans << '\n';
}
