#include <bits/stdc++.h>
const int MAXN = 1e5, MOD = 998244353;
int n, ecnt, head[MAXN + 5], f[MAXN + 5];
struct Edge {
  int to, nxt;
} graph[MAXN * 2 + 5];
inline void subeq(int& a, const int b) { (a -= b) < 0 && (a += MOD); }
inline int mul(const int a, const int b) { return int(1ll * a * b % MOD); }
inline int mpow(int a, int b) {
  int ret = 1;
  for (; b; a = mul(a, a), b >>= 1) ret = mul(ret, b & 1 ? a : 1);
  return ret;
}
inline void link(const int u, const int v) {
  graph[++ecnt] = {v, head[u]}, head[u] = ecnt;
  graph[++ecnt] = {u, head[v]}, head[v] = ecnt;
}
inline bool check(const int u, const int fa, const int k) {
  static int val[MAXN + 5];
  val[u] = 0;
  for (int i = head[u], v; i; i = graph[i].nxt) {
    if ((v = graph[i].to) != fa) {
      if (!check(v, u, k)) return false;
    }
  }
  if (val[u] % k) {
    if (!fa || (val[u] + 1) % k) return false;
  } else if (fa)
    ++val[fa];
  return true;
}
inline void allClear() {
  ecnt = 0;
  for (int i = 1, repi = n; i <= repi; ++i) head[i] = 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n), allClear();
    for (int i = 2, repi = n; i <= repi; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      link(u, v);
    }
    f[1] = mpow(2, n - 1);
    for (int i = 2, repi = n - 1; i <= repi; ++i)
      if (!((n - 1) % i)) f[i] = check(1, 0, i);
    f[n] = 0;
    for (int i = n, peri = 1; i >= peri; --i)
      for (int j = 2, repj = n / i; j <= repj; ++j) subeq(f[i], f[i * j]);
    for (int i = 1, repi = n; i <= repi; ++i)
      printf("%d%c", f[i], i < n ? ' ' : '\n');
  }
  return 0;
}
