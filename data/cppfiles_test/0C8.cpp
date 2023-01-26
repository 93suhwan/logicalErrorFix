#include <bits/stdc++.h>
const int N = 3e6 + 100;
const int mod = 1e9 + 7;
long long ifac[N], fact[N];
long long inv[N];
long long fp(long long a, long long b) {
  long long r = 1ll;
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (r *= a) %= mod;
  return r;
}
int n, q, lim;
std::array<long long, 3> acc[N];
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0), std::cout.tie(0);
  std::cin >> n >> q;
  lim = N - 1, ifac[0] = fact[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= lim; i++) fact[i] = (fact[i - 1] * i) % mod;
  ifac[lim] = fp(fact[lim], mod - 2);
  for (int i = lim - 1; i; --i) ifac[i] = (ifac[i + 1] * (i + 1)) % mod;
  for (int i = 2; i <= lim; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  acc[1] = {(3 * n - 1) * 1ll * n % mod * inv[2] % mod,
            (3 * n + 1) * 1ll * n % mod * inv[2] % mod,
            (3 * n + 3) * 1ll * n % mod * inv[2] % mod};
  for (int i = 2; i <= 3 * n; i++) {
    long long tmpx = i * 1ll * acc[i - 1][0] % mod;
    long long tmpy = i * 1ll * acc[i - 1][1] % mod;
    long long all = fact[3 * n + 1] * ifac[3 * n - i] % mod * inv[i + 1] % mod;
    acc[i][0] = ((all - tmpx * 2 - tmpy) % mod + mod) % mod * inv[3] % mod;
    acc[i][1] = (acc[i][0] + tmpx) % mod;
    acc[i][2] = (acc[i][1] + tmpy) % mod;
  }
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << acc[x][2] * ifac[x] % mod << '\n';
  }
}
