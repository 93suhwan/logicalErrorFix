#include <bits/stdc++.h>
using namespace std;
namespace jyy {
const int mod = 998244353, N = 200010;
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
int dp[2110][2110], g[2110][2110], n, k, b[4110], s[4110];
int main() {
  cin >> n >> k;
  init(n + k);
  for (int i = 1; i <= n; i++) b[i] = read();
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2 * n; j++) s[j] = 0;
    for (int j = max(0, b[i - 1] - k); j <= min(i - 1, b[i - 1] + k); j++) {
      for (int w = 0; w <= i - 1; w++) {
        g[j][w] = qmo(g[j][w] + 1ll * dp[j][w] * (w + j) % mod - mod);
        g[j][w + 1] = qmo(g[j][w + 1] + dp[j][w] - mod);
      }
      if (j && j >= b[i] - k && j <= b[i] + k)
        for (int w = 0; w <= i - 1; w++)
          g[j][w] = qmo(g[j][w] + 1ll * s[j + w - 1] * ifac[w] % mod - mod);
      for (int w = 0; w <= i - 1; w++)
        s[j + w] = qmo(s[j + w] + 1ll * dp[j][w] * fac[w] % mod - mod);
    }
    for (int j = max(min(i - 1, b[i - 1] + k) + 1, b[i] - k);
         j <= min(b[i] + k, i); j++) {
      for (int w = 0; w <= i; w++)
        g[j][w] = qmo(g[j][w] + 1ll * s[j + w - 1] * ifac[w] % mod - mod);
    }
    for (int j = max(0, b[i - 1] - k); j <= min(i - 1, b[i - 1] + k); j++) {
      for (int w = 0; w <= i - 1; w++) {
        dp[j][w] = 0;
      }
    }
    for (int j = max(0, b[i] - k); j <= min(i, b[i] + k); j++) {
      for (int w = 0; w <= i; w++) dp[j][w] = g[j][w], g[j][w] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      ans = qmo(ans + 1ll * dp[i][j] * C(n - i, j) % mod * fac[j] % mod - mod);
  cout << ans;
}
