#include <bits/stdc++.h>
using namespace std;
const int nax = 2 * (int)1e5 + 10;
const int INF = (int)1e9 + 47;
vector<int> g[nax];
struct segment_tree {
  vector<pair<int, int>> t;
  int sz;
  vector<int> sub;
  const int no_operation = -INT_MAX;
  void init(int n) {
    sz = 1;
    while (sz <= n) sz *= 2;
    t.resize(2 * sz - 1);
    sub.assign(sz * 2 - 1, no_operation);
  }
  pair<int, int> combine(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    if (a.second > b.second) return b;
    return a;
  }
  void build(int v, int tl, int tr) {
    if (tr - tl == 1) {
      t[v] = {0, tl};
    } else {
      int tm = (tl + tr) / 2;
      build(v * 2 + 1, tl, tm);
      build(v * 2 + 2, tm, tr);
      t[v] = combine(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }
  void upd(int v, int tl, int tr, int val) {
    t[v].first -= val;
    if (sub[v] == no_operation) sub[v] = 0;
    sub[v] += val;
  }
  void push(int v, int tl, int tr) {
    if (tr - tl == 1 || sub[v] == no_operation) return;
    int tm = (tl + tr) / 2;
    upd(v * 2 + 1, tl, tm, sub[v]);
    upd(v * 2 + 2, tm, tr, sub[v]);
    sub[v] = no_operation;
  }
  pair<int, int> get(int v, int tl, int tr, int l, int r) {
    if (l >= tr || r <= tl) return {-1, -1};
    push(v, tl, tr);
    if (tl >= l && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    pair<int, int> s1 = get(v * 2 + 1, tl, tm, l, r);
    pair<int, int> s2 = get(v * 2 + 2, tm, tr, l, r);
    return combine(s1, s2);
  }
  pair<int, int> get(int l, int r) { return get(0, 0, sz, l, r + 1); }
  void update(int v, int tl, int tr, int l, int r, int val) {
    if (l >= tr || r <= tl) return;
    push(v, tl, tr);
    if (tl >= l && tr <= r) {
      upd(v, tl, tr, val);
      return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2 + 1, tl, tm, l, r, val);
    update(v * 2 + 2, tm, tr, l, r, val);
    t[v] = combine(t[v * 2 + 1], t[v * 2 + 2]);
  }
  void update(int l, int r, int val) { update(0, 0, sz, l, r + 1, val); }
} T;
int lvl[nax], tin[nax], tout[nax];
int cnt = 0;
int timer = 0;
int ver[nax];
int seen[nax];
int par[nax];
int sz[nax];
int rsz[nax];
int blue = 0;
int vr[nax];
void dfs(int v, int p = -1) {
  par[v] = p;
  if (g[v].size() == 1 && p != -1) cnt++;
  if (p != -1) lvl[v] = lvl[p] + 1;
  tin[v] = timer++;
  vr[tin[v]] = v;
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
  }
  tout[v] = timer;
}
void dfs2(int v, int p = -1) {
  sz[v] = ver[v];
  rsz[v] = 1;
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs2(to, v);
    sz[v] += sz[to];
    rsz[v] += rsz[to];
  }
}
void dfs_ans(int v, int p = -1) {
  if (sz[v] == 0) {
    blue += rsz[v];
  } else {
    for (auto to : g[v]) {
      if (to == p) continue;
      dfs_ans(to, v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  T.init(n);
  T.build(0, 0, T.sz);
  for (int i = 0; i < n; i++) T.update(tin[i], tin[i], -lvl[i]);
  for (int i = 0; i < min(k, cnt); i++) {
    pair<int, int> v = T.get(0, n);
    ver[vr[v.second]] = 1;
    int cur = vr[v.second];
    while (cur != -1 && !seen[cur]) {
      T.update(tin[cur], tout[cur] - 1, 1);
      seen[cur] = 1;
      cur = par[cur];
    }
  }
  dfs2(0);
  dfs_ans(0);
  int w = n - blue - min(k, cnt);
  int r = min(k, cnt);
  if (cnt < k) {
    r = k;
    blue = 0;
    w = n - r;
  }
  cout << w * 1ll * (r - blue) << '\n';
}
