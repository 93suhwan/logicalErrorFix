#include <bits/stdc++.h>
using namespace std;
int n, q;
const long long N = 2e5 + 100;
vector<long long> v[N];
long long dfn[N], num[N], val[N], sz[N], hs[N], tp[N], dep[N], f[N];
inline void dfs(long long x, long long fa) {
  sz[x] = 1;
  long long num = 0;
  dep[x] = dep[fa] + 1;
  f[x] = fa;
  for (auto y : v[x]) {
    if (y == fa) continue;
    dfs(y, x);
    sz[x] += sz[y];
    if (num < sz[y]) hs[x] = y, num = sz[y];
  }
}
long long cnt;
inline void redfs(long long x, long long fa, long long top) {
  tp[x] = top;
  dfn[x] = ++cnt;
  num[cnt] = x;
  if (hs[x]) redfs(hs[x], x, top);
  for (auto y : v[x]) {
    if (y == fa || y == hs[x]) continue;
    redfs(y, x, y);
  }
}
struct seg {
  long long l, r, v;
} t[N << 2];
long long a[N];
inline void build(long long p, long long l, long long r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].v = abs(val[num[l]]);
    return;
  }
  long long mid = l + r >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
  t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}
inline void modify(long long p, long long x, long long v) {
  if (t[p].l == t[p].r) {
    t[p].v = v;
    return;
  }
  long long mid = t[p].l + t[p].r >> 1;
  if (x <= mid)
    modify(p << 1, x, v);
  else
    modify(p << 1 | 1, x, v);
  t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}
inline long long query(long long p, long long x, long long y) {
  if (x <= t[p].l && t[p].r <= y) {
    return t[p].v;
  }
  long long mid = t[p].l + t[p].r >> 1;
  if (y <= mid) return query(p << 1, x, y);
  if (x > mid) return query(p << 1 | 1, x, y);
  return query(p << 1, x, y) + query(p << 1 | 1, x, y);
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> val[i], val[i] = abs(val[i]);
  for (long long i = 1; i <= n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
  }
  dfs(1, 0);
  redfs(1, 0, 1);
  build(1, 1, n);
  for (long long i = 1; i <= q; i++) {
    long long opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      modify(1, dfn[x], abs(y));
      val[x] = abs(y);
    } else {
      long long ans = 0, X = x, Y = y;
      ;
      while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
        ans += query(1, dfn[tp[x]], dfn[x]);
        x = f[tp[x]];
      }
      if (dep[x] < dep[y]) swap(x, y);
      ans += query(1, dfn[y], dfn[x]);
      cout << ans * 2 - val[X] - val[Y] << "\n";
    }
  }
}
