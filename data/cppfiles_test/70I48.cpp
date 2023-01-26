#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 10;
long long fp(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans % mod;
}
long long jc[12], jie[N][10], sum[N], cnt[N];
long long n, q, x, s, m, l, r, d, a, f, u = 7;
long long C(long long x, long long y) { return jc[x] / jc[y] / jc[x - y]; }
int main() {
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    sum[i] = (sum[i - 1] + x) % mod;
    cnt[i] = (cnt[i - 1] + fp(x, u)) % mod;
  }
  jie[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= u; j++) jie[i][j] = (jie[i - 1][j] + fp(i, j)) % mod;
  jc[0] = 1;
  for (int i = 1; i <= u + 2; i++) jc[i] = jc[i - 1] * i;
  while (q--) {
    scanf("%lld%lld%lld", &l, &r, &d);
    m = r - l + 1;
    s = sum[r] - sum[l - 1];
    f = ((s - ((m - 1) * m / 2) % mod * (d % mod) + mod) % mod *
             fp(m, mod - 2) % mod +
         mod) %
        mod;
    a = 0;
    for (int j = 0; j <= u; j++) {
      long long dj = fp(d, j), fj = fp(f, u - j);
      a = (a + jie[m - 1][j] % mod * C(u, j) % mod * dj % mod * fj % mod) % mod;
    }
    long long b = (cnt[r] - cnt[l - 1] + mod) % mod;
    if (a != b)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
