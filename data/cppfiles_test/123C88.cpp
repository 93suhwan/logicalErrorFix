#include <bits/stdc++.h>
struct SegmentTree {
  static const int mxn = 1 << 18;
  int tag[mxn << 1];
  int mx[mxn << 1], mxu[mxn << 1];
  inline void push(int x, int v) {
    tag[x] += v;
    mx[x] += v;
  }
  inline void pushdown(int x) {
    if (tag[x]) {
      push(x << 1, tag[x]);
      push(x << 1 | 1, tag[x]);
      tag[x] = 0;
    }
  }
  inline void pushup(int x) {
    if (mx[x << 1] < mx[x << 1 | 1]) {
      mx[x] = mx[x << 1 | 1];
      mxu[x] = mxu[x << 1 | 1];
    } else {
      mx[x] = mx[x << 1];
      mxu[x] = mxu[x << 1];
    }
  }
  void init(int n, int a[]) {
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i < (int)(mxn); ++i) mx[i + mxn] = 0, mxu[i + mxn] = -1;
    for (int i = 0; i < (int)(n); ++i) mx[i + mxn] = a[i], mxu[i + mxn] = i;
    for (int i = mxn - 1; i; --i) pushup(i);
    fprintf(stderr, "%d %d\n", mx[1], mxu[1]);
  }
  inline void update(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
    if (l <= a && b <= r) return push(i, v);
    if (r <= a || b <= l) return;
    pushdown(i);
    int m = (a + b) >> 1;
    update(l, r, v, i << 1, a, m);
    update(l, r, v, i << 1 | 1, m, b);
    pushup(i);
  }
} seg;
const int mxn = 2e5 + 5;
int n, K;
std::vector<int> adj[mxn];
int fa[mxn], dep[mxn];
int sz[mxn], son[mxn], top[mxn];
int on[mxn], dfn[mxn], ed[mxn], tim;
void dfs(int u, int p) {
  sz[u] = 1, son[u] = -1;
  for (int v : adj[u]) {
    if (v == p) continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs(v, u);
    sz[u] += sz[v];
    if (!~son[u] || sz[v] > sz[son[u]]) son[u] = v;
  }
}
void hld(int u, int p) {
  top[u] = ~p && u == son[p] ? top[p] : u;
  on[tim] = u;
  dfn[u] = tim++;
  if (son[u] != -1) hld(son[u], u);
  for (int v : adj[u]) {
    if (v == p || v == son[u]) continue;
    hld(v, u);
  }
  ed[u] = tim;
}
std::set<int> unreal;
inline void UPDATE(int l, int r) {
  for (auto it = unreal.lower_bound(l); it != unreal.end() && *it <= r;
       it = unreal.erase(it)) {
    seg.update(dfn[on[*it]], ed[on[*it]], -1);
  }
}
int main() {
  scanf("%d %d", &n, &K);
  for (int i = 0; i < (int)(n - 1); ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  hld(0, -1);
  static int temp[mxn];
  for (int i = 0; i < (int)(n); ++i) temp[dfn[i]] = dep[i] + 1;
  seg.init(n, temp);
  for (int i = 0; i < (int)(n); ++i) unreal.insert(i);
  long long ans = -(1LL << 60);
  for (int r = 0; r <= K; ++r) {
    int b = std::min((int)unreal.size(), n / 2);
    long long cur = 1LL * (n - r - b) * (r - b);
    ans = std::max(ans, cur);
    if (r < K) {
      int u = on[seg.mxu[1]];
      while (top[u]) {
        UPDATE(dfn[top[u]], dfn[u]);
        u = fa[top[u]];
      }
      UPDATE(dfn[top[u]], dfn[u]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
