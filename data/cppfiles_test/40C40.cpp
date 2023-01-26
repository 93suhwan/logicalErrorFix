#include <bits/stdc++.h>
using namespace std;
namespace jyy {
const int mod = 998244353, N = 600010;
const double eps = 1e-8;
inline int read() {
  static int x = 0, f = 1;
  x = 0, f = 1;
  static char ch = getchar();
  while (ch < '0' || ch > '9') {
    (ch == '-') ? f *= -1 : f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + int(ch - 48), ch = getchar();
  return x * f;
}
inline void fw(int x) {
  if (x < 0) putchar('-'), x = -x;
  x >= 10 ? fw(x / 10), 1 : 0;
  putchar(char(x % 10 + 48));
}
inline int qmo(int x) { return x + ((x >> 31) & mod); }
inline int ksm(int x, int y) {
  int tmp = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) tmp = 1ll * tmp * x % mod;
  return tmp;
}
inline int inv(int x) { return ksm(x, mod - 2); }
int tot, head[N], fa[N];
struct edge {
  int to, next;
} dat[N * 2];
void add_edge(int x, int y) { dat[++tot] = (edge){y, head[x]}, head[x] = tot; }
inline int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }
inline int merge(int x, int y) {
  return find(x) != find(y) ? fa[find(x)] = find(y), 0 : 1;
}
inline int low(int x) { return x & -x; }
int ifac[N], fac[N];
inline void init(int x) {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= x; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[x] = inv(fac[x]);
  for (int i = x - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
inline int C(int x, int y) {
  return (x < y || y < 0 || x < 0)
             ? 0
             : 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
}  // namespace jyy
using namespace jyy;
int pd[N], n, R[N], a[N], vis[N], dep[N], m, b[N];
char c[N];
void dfs(int x, int f) {
  vis[x] = 1;
  dep[x] = dep[f] + 1;
  fa[x] = f;
  for (int i = head[x]; i; i = dat[i].next) {
    int t = dat[i].to;
    if (t == f || vis[t]) continue;
    dfs(t, x);
  }
}
void work(int x, int y) {
  deque<int> q1, q2;
  while (dep[x] > dep[y]) q1.push_back(x), x = fa[x];
  while (dep[x] < dep[y]) q2.push_front(y), y = fa[y];
  while (x != y) q1.push_back(x), q2.push_front(y), x = fa[x], y = fa[y];
  q1.push_back(x);
  cout << q1.size() + q2.size() << endl;
  while (q1.size()) printf("%d ", q1.front()), q1.pop_front();
  while (q2.size()) printf("%d ", q2.front()), q2.pop_front();
  puts("");
}
void solve() {
  n = read(), m = read();
  for (int i = 1, x, y; i <= m; i++)
    x = read(), y = read(), add_edge(x, y), add_edge(y, x);
  dfs(1, 0);
  int q = read();
  for (int i = 1; i <= q; i++) {
    a[i] = read(), b[i] = read();
    pd[a[i]] ^= 1;
    pd[b[i]] ^= 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += pd[i];
  if (cnt) {
    puts("NO");
    cout << cnt / 2 << endl;
    return;
  }
  puts("YES");
  for (int i = 1; i <= q; i++) {
    work(a[i], b[i]);
  }
}
int main() {
  int T = 1;
  while (T--) solve();
}
