#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int fac[N], inv[N], ans, n, mod, vis[N][N][N], f[N][N][N];
inline int ksm(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) ret = 1ll * ret * x % mod;
  return ret;
}
inline void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = ksm(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
inline void inc(int &x, int y) { x = (x + y >= mod) ? x + y - mod : x + y; }
inline int solve(int a, int x, int s, int k) {
  if (x == n) return 1;
  if (!k) return inv[n - x];
  int &g = f[x][s][k];
  if (vis[x][s][k] == a) return g;
  vis[x][s][k] = a;
  g = 0;
  for (int i = 0; s + i * k <= a && x + i <= n; ++i) {
    int mx = n - (x + i);
    if (k > 1 && mx + 1 - a > k - 1) continue;
    g = (g + 1ll * solve(a, x + i, s + i * k, k - 1) * inv[i]) % mod;
  }
  return g;
}
int main() {
  scanf("%d%d", &n, &mod);
  init(n);
  int sq = ceil(sqrt(n) + 0.5);
  for (int i = max(1, n - 2 * sq - 1); i <= n; ++i)
    inc(ans, solve(i, 0, 0, n - i + 1));
  printf("%d\n", 1ll * ans * fac[n] % mod);
  return 0;
}
