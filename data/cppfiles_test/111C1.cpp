#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void _debug() { std::cerr << std::endl; }
template <typename T, typename... U>
void _debug(T t, U... args) {
  std::cerr << " " << t;
  _debug(args...);
}
const int maxn = 2200;
const int mod = 998244353;
void add(int &x, int v) {
  x += v;
  if (x >= mod) x -= mod;
}
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * a * ans % mod;
    b >>= 1;
    a = 1ll * a * a % mod;
  }
  return ans;
}
int fac[maxn], inv[maxn];
int C(int i, int j) {
  if (i < j) return 0;
  return 1ll * fac[i] * inv[j] % mod * inv[i - j] % mod;
}
int invC(int i, int j) {
  if (i < j) return 0;
  return 1ll * fac[j] * fac[i - j] % mod * inv[i] % mod;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int Inv(int x) { return qpow(x, mod - 2); }
int f[2][maxn][maxn], n, k, pf[maxn][maxn], b[maxn], mx[maxn], invc[maxn][maxn],
    c[maxn][maxn];
int main() {
  init();
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) invc[i][j] = invC(i, j), c[i][j] = C(i, j);
  }
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<pii> vis;
  f[0][0][0] = 1;
  pf[0][0] = 1;
  vis.push_back({0, 0});
  for (int i = 1; i <= n; i++) {
    int now = i & 1, pre = now ^ 1;
    for (int j = max(0, b[i] - k); j <= min(b[i] + k, n + 1); j++) {
      for (int g = 0; g <= i; g++) {
        add(f[now][j][g], 1ll * (j + g) * f[pre][j][g] % mod);
        add(f[now][j][g + 1], 1ll * (n - j - g) * f[pre][j][g] % mod);
      }
    }
    for (int j = max(0, b[i] - k); j <= min(b[i] + k, n + 1); j++) {
      for (int g = 0; g <= i; g++) {
        if (j)
          add(f[now][j][g], 1ll * pf[j + g - 1][min(mx[j + g - 1], j - 1)] *
                                c[n - j][g] % mod);
      }
    }
    memset(mx, 0, sizeof(mx));
    for (const auto &[u, v] : vis) pf[u][v] = 0, f[pre][v][u - v] = 0;
    vis.clear();
    vis.reserve(2 * k * i);
    for (int j = max(0, b[i] - k); j <= min(b[i] + k, n + 1); j++) {
      for (int g = 0; g <= i; g++) {
        assert(j >= 0);
        add(pf[j + g][j], 1ll * f[now][j][g] * invc[n - j][g] % mod);
        vis.push_back({j + g, j});
        mx[j + g] = max(mx[j + g], j);
      }
    }
    for (const auto &[u, v] : vis)
      if (v) add(pf[u][v], pf[u][v - 1]);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) add(ans, f[n & 1][i][j]);
  }
  cout << ans;
}
