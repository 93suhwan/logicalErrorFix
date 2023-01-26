#include <bits/stdc++.h>
int const mod = 998244353, inv2 = (mod + 1) / 2;
int fac[10000010], ifac[10000010], pw[10000010];
int pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return res;
}
int solve(int n, int k, int x) {
  int pk = pow(2, k);
  if (x == 0) {
    if (n > k) return 0;
    int ans = 1;
    for (int i = 0; i < n; i++) ans = 1ll * ans * (pk - pw[i] + mod) % mod;
    return ans;
  }
  int ans = 0, p = 1, d = pow(2, n);
  for (int i = 0; i < k; i++) {
    ans = (ans + 1ll * p * ifac[i]) % mod;
    p = 1ll * p * (pk - pw[i + 1] + mod) % mod * (1 - d + mod) % mod;
    d = 1ll * d * inv2 % mod;
  }
  return ans;
}
int main() {
  fac[0] = 1, pw[0] = 1;
  for (int i = 1; i <= 10000000; i++)
    pw[i] = 2 * pw[i - 1] % mod,
    fac[i] = 1ll * fac[i - 1] * (1 - pw[i] + mod) % mod;
  ifac[10000000] = pow(fac[10000000], mod - 2);
  for (int i = 10000000; i; i--)
    ifac[i - 1] = 1ll * ifac[i] * (1 - pw[i] + mod) % mod;
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    printf("%d\n", solve(n, k, x));
  }
  return 0;
}
