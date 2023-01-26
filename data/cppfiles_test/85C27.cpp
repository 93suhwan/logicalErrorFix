#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 8;
int mod;
int qpow(int x, int y = mod - 2) {
  int res = 1;
  for (; y; x = (long long)x * x % mod, y >>= 1)
    if (y & 1) res = (long long)res * x % mod;
  return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
  fac[0] = ifac[0] = inv[1] = 1;
  for (int i = (2); i <= (x); ++i)
    inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
  for (int i = (1); i <= (x); ++i)
    fac[i] = (long long)fac[i - 1] * i % mod,
    ifac[i] = (long long)ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
  return x < y || y < 0 ? 0
                        : (long long)fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, dp[N][N], ns;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> mod;
  init(n + 1);
  for (int mn = (max(n - 20, 0)); mn <= (n + 1); ++mn) {
    memset(dp, 0, sizeof(dp));
    for (int i = (1); i <= (min(mn, n)); ++i) dp[i][0] = ifac[i];
    for (int i = (mn + 1); i <= (n + 1); ++i)
      for (int a = (i - 1); a >= (1); --a)
        for (int b = (0); b <= (mn); ++b)
          if (dp[a][b]) {
            int up =
                min(min(i - a, (mn * (i - a) - b) / i), (mn - b) / (i - mn));
            for (int k = (1); k <= (up); ++k)
              (dp[a + k][b + (i - mn) * k] +=
               (long long)ifac[k] * dp[a][b] % mod) %= mod;
          }
    for (int i = (0); i <= (mn); ++i) (ns += dp[n][i]) %= mod;
  }
  cout << (long long)ns * fac[n] % mod << '\n';
  return 0;
}
