#include <bits/stdc++.h>
using namespace std;
char _c;
bool _f;
template <class T>
inline void IN(T &x) {
  x = 0, _f = 0;
  while (_c = getchar(), !isdigit(_c))
    if (_c == '-') _f = 1;
  while (isdigit(_c)) x = x * 10 + _c - '0', _c = getchar();
  if (_f) x = -x;
}
template <class T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
const int N = 3e5 + 5;
const int LogN = 19;
long long ans[N];
bool vis[N];
int n, q, k, atop, a[N], id[N], asta[N], Lpos[N], Rpos[N];
int dep[N], fa[N][LogN];
struct Node {
  int l, r, id;
};
vector<Node> qsta[N];
vector<int> to[N];
void dfs1(int u, int pre) {
  dep[u] = dep[pre] + 1, fa[u][0] = pre;
  for (int i = 1; i <= 18; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : to[u]) dfs1(v, u);
}
const int M = 1e7 + 5;
int cnt, rt[N], lc[M], rc[M];
long long sum[M], tag[M];
inline void update(int x, long long y) { tag[x] += y, sum[x] += y; }
inline void pushdown(int x) {
  if (tag[x]) {
    if (lc[x]) update(lc[x], tag[x]);
    if (rc[x]) update(rc[x], tag[x]);
    tag[x] = 0;
  }
}
void insert(int &x, int l, int r, int pos) {
  if (!x) x = ++cnt;
  if (l == r) return;
  pushdown(x);
  pos <= ((l + r) >> 1) ? insert(lc[x], l, ((l + r) >> 1), pos)
                        : insert(rc[x], ((l + r) >> 1) + 1, r, pos);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  pushdown(x), pushdown(y);
  lc[x] = merge(lc[x], lc[y]);
  rc[x] = merge(rc[x], rc[y]);
  return x;
}
long long query(int x, int l, int r, int pos) {
  if (l == r) return sum[x];
  pushdown(x);
  return pos <= ((l + r) >> 1) ? query(lc[x], l, ((l + r) >> 1), pos)
                               : query(rc[x], ((l + r) >> 1) + 1, r, pos);
}
void modify(int x, int l, int r, int L, int R, long long val) {
  if (!x) return;
  if (L <= l && r <= R) return update(x, val), void();
  pushdown(x);
  if (L <= ((l + r) >> 1)) modify(lc[x], l, ((l + r) >> 1), L, R, val);
  if (R > ((l + r) >> 1)) modify(rc[x], ((l + r) >> 1) + 1, r, L, R, val);
}
void dfs2(int u, int pre) {
  vis[u] = true;
  insert(rt[u], 1, n, id[u]);
  for (auto v : to[u]) dfs2(v, u), rt[u] = merge(rt[u], rt[v]);
  for (auto que : qsta[u]) {
    int buf = (que.r - (que.l + ((u - que.l + k - 1) / k) * k) + k) / k;
    ans[que.id] = query(rt[u], 1, n, id[que.l]) + 1ll * a[u] * buf;
  }
  if (pre) {
    int t1 = (pre - u - 1 + k - 1) / k;
    int t2 = (pre - u - 1) / k;
    int T = u % k;
    int L = (T + 1) % k;
    int R = (T + ((pre - u - 1) % k)) % k;
    update(rt[u], 1ll * a[u] * t2);
    if ((pre - u - 1) % k) {
      if (L <= R)
        if (Lpos[L] <= Rpos[R])
          modify(rt[u], 1, n, Lpos[L], Rpos[R], 1ll * a[u] * (t1 - t2));
        else {
          if (Lpos[L] <= n)
            modify(rt[u], 1, n, Lpos[L], n, 1ll * a[u] * (t1 - t2));
          if (Rpos[R] >= 1)
            modify(rt[u], 1, n, 1, Rpos[R], 1ll * a[u] * (t1 - t2));
        }
    }
    if (Lpos[T] <= Rpos[T]) modify(rt[u], 1, n, Lpos[T], Rpos[T], a[u]);
  }
}
int main() {
  IN(n), IN(q), IN(k);
  for (int i = 1; i <= n; ++i) IN(a[i]);
  for (int i = 1; i <= n; ++i) {
    while (atop && a[asta[atop]] > a[i]) to[i].push_back(asta[atop]), --atop;
    asta[++atop] = i;
  }
  for (int i = n; i >= 1; --i)
    if (!dep[i]) dfs1(i, 0);
  for (int l, r, t, i = 1; i <= q; ++i) {
    IN(l), IN(r), t = l;
    for (int i = 18; i >= 0; --i)
      if (fa[t][i] && fa[t][i] <= r) t = fa[t][i];
    qsta[t].push_back((Node){l, r, i});
  }
  for (int tmp = 0, t = 0; t < k; ++t) {
    Lpos[t] = tmp + 1;
    for (int i = t; i <= n; i += k) id[i] = ++tmp;
    Rpos[t] = tmp;
  }
  for (int i = n; i >= 1; --i)
    if (!vis[i]) dfs2(i, 0);
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
