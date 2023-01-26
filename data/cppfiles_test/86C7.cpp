#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5, mod = 998244353;
int T, n, k, x, pw[N], a[N];
int qpow(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) ret = 1ll * ret * x % mod;
  return ret;
}
int main() {
  pw[0] = 1;
  for (int i = (1); i <= (N - 1); i++) pw[i] = 2ll * pw[i - 1] % mod;
  int mul = 1;
  for (int i = (1); i <= (N - 1); i++) mul = 1ll * mul * (pw[i] - 1) % mod;
  a[N - 1] = qpow(mul, mod - 2);
  for (int i = (N - 2); i >= (1); i--)
    a[i] = 1ll * a[i + 1] * (pw[i + 1] - 1) % mod;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &k, &x);
    if (!x) {
      if (n > k)
        puts("0");
      else {
        int ans = 1;
        for (int i = (0); i <= (n - 1); i++)
          ans = 1ll * ans * (pw[k] - pw[i] + mod) % mod;
        printf("%d\n", ans);
      }
    } else {
      int ans = pw[k] - 1, cur = 1, t = qpow(2, n), iv = qpow(2, mod - 2);
      for (int i = 1, c = pw[k] - 1; i < k; i++) {
        cur = 1LL * cur * (t - 1) % mod, t = 1ll * t * iv % mod,
        c = 1ll * c * (pw[k] - pw[i] + mod) % mod;
        (ans += 1ll * c * cur % mod * a[i] % mod) %= mod;
      }
      printf("%lld\n", 1ll * qpow(pw[k] - 1, mod - 2) * ans % mod);
    }
  }
  return 0;
}
