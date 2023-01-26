#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, Mx, ans, tr[maxn], vis[maxn], f[maxn], g[maxn], id[maxn];
struct BIT {
  int tr[maxn];
  inline void add(int x, int y) {
    for (int i = x; i; i -= i & (-i)) tr[i] += y;
  }
  inline int query(int x) {
    int res = 0;
    for (int i = x; i <= n + n; i += i & (-i)) res += tr[i];
    return res;
  }
} t1, t2;
inline void add(int x, int y) {
  for (int i = x; i <= n + n; i++) tr[i] = max(tr[i], y);
}
inline int query(int x) {
  int res = 0;
  for (int i = x; i; i -= i & (-i)) res = max(res, tr[i]);
  return res;
}
struct node {
  int l, r;
} p[maxn];
inline int cmp1(node x, node y) { return x.r < y.r; }
inline int cmp2(int x, int y) { return p[x].l < p[y].l; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) p[i].l = read(), p[i].r = read(), id[i] = i;
  m = read();
  for (int i = 1, x; i <= m; i++)
    x = read(), Mx = max(Mx, p[x].r), vis[p[x].r] = 1;
  sort(p + 1, p + 1 + n, cmp1);
  for (int i = 1; i <= n; i++) {
    f[i] = (t1.query(p[i].l) + t2.query(p[i].l)) % mod;
    g[i] = query(p[i].l);
    t1.add(p[i].l, f[i]);
    t2.add(p[i].l, 1);
    if (vis[p[i].r]) add(p[i].l, p[i].r);
  }
  sort(id + 1, id + 1 + n, cmp2);
  for (int i = 1; i <= n; i++) {
    if (p[id[i]].r > Mx) continue;
    if (p[id[i]].r == Mx) Mx = g[id[i]];
    ans = (ans + f[id[i]] + 1) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
