#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T w = 1, ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ '0'), ch = getchar();
  x = x * w;
}
const long long maxn = 200000 + 10;
long long n, m, r, mod;
long long e, beg[maxn], nex[maxn], to[maxn], w[maxn], wt[maxn];
long long a[maxn << 2], laz[maxn << 2];
long long son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
long long res = 0;
inline void add(long long x, long long y) {
  to[++e] = y;
  nex[e] = beg[x];
  beg[x] = e;
}
inline void pushdown(long long rt, long long lenn) {
  laz[rt << 1] += laz[rt];
  laz[rt << 1 | 1] += laz[rt];
  a[rt << 1] += laz[rt] * (lenn - (lenn >> 1));
  a[rt << 1 | 1] += laz[rt] * (lenn >> 1);
  a[rt << 1] %= mod;
  a[rt << 1 | 1] %= mod;
  laz[rt] = 0;
}
inline void build(long long rt, long long l, long long r) {
  if (l == r) {
    a[rt] = wt[l];
    if (a[rt] > mod) a[rt] %= mod;
    return;
  }
  build(rt << 1, l, ((l + r) >> 1));
  build(rt << 1 | 1, ((l + r) >> 1) + 1, r);
  a[rt] = (a[rt << 1] + a[rt << 1 | 1]) % mod;
}
inline void query(long long rt, long long l, long long r, long long L,
                  long long R) {
  if (L <= l && r <= R) {
    res += a[rt];
    res %= mod;
    return;
  } else {
    if (laz[rt]) pushdown(rt, (r - l + 1));
    if (L <= ((l + r) >> 1)) query(rt << 1, l, ((l + r) >> 1), L, R);
    if (R > ((l + r) >> 1)) query(rt << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
  }
}
inline void update(long long rt, long long l, long long r, long long L,
                   long long R, long long k) {
  if (L <= l && r <= R) {
    laz[rt] += k;
    a[rt] += k * (r - l + 1);
  } else {
    if (laz[rt]) pushdown(rt, (r - l + 1));
    if (L <= ((l + r) >> 1)) update(rt << 1, l, ((l + r) >> 1), L, R, k);
    if (R > ((l + r) >> 1)) update(rt << 1 | 1, ((l + r) >> 1) + 1, r, L, R, k);
    a[rt] = (a[rt << 1] + a[rt << 1 | 1]) % mod;
  }
}
inline long long qRange(long long x, long long y) {
  long long ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    res = 0;
    query(1, 1, n, id[top[x]], id[x]);
    ans += res;
    ans %= mod;
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  res = 0;
  query(1, 1, n, id[x], id[y]);
  ans += res;
  return ans % mod;
}
inline void updRange(long long x, long long y, long long k) {
  k %= mod;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    update(1, 1, n, id[top[x]], id[x], k);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  update(1, 1, n, id[x], id[y], k);
}
inline long long qSon(long long x) {
  res = 0;
  query(1, 1, n, id[x], id[x] + siz[x] - 1);
  return res;
}
inline void updSon(long long x, long long k) {
  update(1, 1, n, id[x], id[x] + siz[x] - 1, k);
}
inline void dfs1(long long x, long long f, long long deep) {
  dep[x] = deep;
  fa[x] = f;
  siz[x] = 1;
  long long maxson = -1;
  for (long long i = beg[x]; i; i = nex[i]) {
    long long y = to[i];
    if (y == f) continue;
    dfs1(y, x, deep + 1);
    siz[x] += siz[y];
    if (siz[y] > maxson) son[x] = y, maxson = siz[y];
  }
}
inline void dfs2(long long x, long long topf) {
  id[x] = ++cnt;
  wt[cnt] = w[x];
  top[x] = topf;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (long long i = beg[x]; i; i = nex[i]) {
    long long y = to[i];
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
signed main() {
  read(n);
  read(m);
  r = 1, mod = 1e18;
  for (long long i = 1; i <= n; i++) {
    read(w[i]);
    if (w[i] < 0) w[i] = -w[i];
  }
  for (long long i = 1; i < n; i++) {
    long long a, b;
    read(a);
    read(b);
    add(a, b);
    add(b, a);
  }
  dfs1(r, 0, 1);
  dfs2(r, r);
  build(1, 1, n);
  while (m--) {
    long long k, x, y, z;
    read(k);
    if (k == 1) {
      read(x);
      read(y);
      if (y < 0) y = -y;
      updRange(x, x, y - w[x]);
      w[x] = y;
    } else if (k == 2) {
      read(x);
      read(y);
      printf("%lld\n", qRange(x, y) * 2 - w[x] - w[y]);
    }
  }
}
