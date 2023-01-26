#include <bits/stdc++.h>
using namespace std;
struct segtree_max_add {
  const pair<long long, long long> INF = {-1e9, -1e9};
  vector<pair<long long, long long> > st;
  vector<long long> lz;
  long long n;
  segtree_max_add(long long N) : n(N) {
    st.assign((n << 2) + 5, {0, 0});
    lz.assign((n << 2) + 5, 0);
    build(1, 1, n);
  }
  void build(long long id, long long l, long long r) {
    if (l == r) {
      st[id] = {0, l};
      return;
    }
    long long mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = _max(st[id << 1], st[id << 1 | 1]);
  }
  void push(long long id, long long l, long long r) {
    st[id].first += lz[id];
    if (l != r) {
      lz[id << 1] += lz[id];
      lz[id << 1 | 1] += lz[id];
    }
    lz[id] = 0;
  }
  __attribute__((always_inline)) pair<long long, long long> _max(
      pair<long long, long long> a, pair<long long, long long> b) {
    return (a > b ? a : b);
  }
  void _upd(long long u, long long v, long long val, long long id, long long l,
            long long r) {
    push(id, l, r);
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      lz[id] = val;
      push(id, l, r);
      return;
    }
    long long mid = l + r >> 1;
    _upd(u, v, val, id << 1, l, mid);
    _upd(u, v, val, id << 1 | 1, mid + 1, r);
    st[id] = _max(st[id << 1], st[id << 1 | 1]);
  }
  void upd(long long u, long long v, long long val) {
    _upd(u, v, val, 1, 1, n);
  }
  pair<long long, long long> _query(long long u, long long v, long long id,
                                    long long l, long long r) {
    push(id, l, r);
    if (r < u || l > v) return INF;
    if (l >= u && r <= v) return st[id];
    long long mid = l + r >> 1;
    return _max(_query(u, v, id << 1, l, mid),
                _query(u, v, id << 1 | 1, mid + 1, r));
  }
  pair<long long, long long> query(long long u, long long v) {
    return _query(u, v, 1, 1, n);
  }
};
const long long MAXN = 2e5 + 5;
vector<long long> path[MAXN];
long long dep[MAXN], ver[MAXN];
bool vis[MAXN];
bool leaf[MAXN];
long long par[MAXN];
long long tin[MAXN], tout[MAXN];
void dfs(long long u, long long pre = 0) {
  static long long timer = 0;
  tin[u] = ++timer;
  ver[timer] = u;
  dep[u] = dep[pre] + 1;
  par[u] = pre;
  leaf[u] = (pre && path[u].size() == 1);
  for (long long v : path[u])
    if (v != pre) dfs(v, u);
  tout[u] = timer;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 1, u, v; i < n; i++)
    cin >> u >> v, path[u].push_back(v), path[v].push_back(u);
  dfs(1);
  long long cl = 0;
  for (long long i = 1; i <= n; i++) cl += leaf[i];
  segtree_max_add t(n);
  for (long long i = 1; i <= n; i++) {
    if (leaf[i])
      t.upd(tin[i], tin[i], dep[i]);
    else
      t.upd(tin[i], tin[i], -1e9);
  }
  vis[0] = 1;
  long long cnt = 0;
  long long ans = -1e18;
  for (long long i = 1; i <= min(cl, k); i++) {
    auto vv = t.query(1, n);
    long long v = ver[vv.second];
    t.upd(tin[v], tin[v], -1e9);
    assert(leaf[v]);
    long long res = 0;
    for (; !vis[v]; v = par[v]) {
      vis[v] = 1;
      cnt++;
      t.upd(tin[v], tout[v], -1);
    }
    cnt--;
    assert(cnt <= n && i + cnt <= n);
    ans = max(ans, (i - (n - cnt - i)) * cnt);
  }
  if (cl < k) {
    for (long long i = cl + 1; i <= k; i++) ans = max(ans, (n - i) * i);
  }
  cout << ans << '\n';
}
