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
long long jc[20], jie[N][20], sum[N], cnt1[N], cnt2[N];
long long n, q, x, s, m, l, r, d, a1, a2, f, u1 = 7, u2 = 2;
long long C(long long x, long long y) {
  return (jc[x] / jc[y] / jc[x - y]) % mod;
}
int main() {
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    sum[i] = (sum[i - 1] + x) % mod;
    cnt1[i] = (cnt1[i - 1] + fp(x, u1)) % mod;
    cnt2[i] = (cnt2[i - 1] + fp(x, u2)) % mod;
  }
  jie[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 15; j++) jie[i][j] = (jie[i - 1][j] + fp(i, j)) % mod;
  jc[0] = 1;
  for (int i = 1; i <= 15; i++) jc[i] = jc[i - 1] * i;
  while (q--) {
    scanf("%lld%lld%lld", &l, &r, &d);
    m = r - l + 1;
    s = sum[r] - sum[l - 1];
    f = ((s - ((m - 1) * m / 2) % mod * (d % mod) % mod + mod) % mod *
             fp(m, mod - 2) % mod +
         mod) %
        mod;
    a1 = 0;
    a2 = 0;
    for (int j = 0; j <= u1; j++) {
      long long dj = (fp(d, j) + mod) % mod, fj = (fp(f, u1 - j) + mod) % mod;
      a1 = ((a1 + jie[m - 1][j] % mod * C(u1, j) % mod * dj % mod * fj % mod) %
                mod +
            mod) %
           mod;
    }
    for (int j = 0; j <= u2; j++) {
      long long dj = (fp(d, j) + mod) % mod, fj = (fp(f, u2 - j) + mod) % mod;
      a2 = ((a2 + jie[m - 1][j] % mod * C(u2, j) % mod * dj % mod * fj % mod) %
                mod +
            mod) %
           mod;
    }
    long long b1 = (cnt1[r] - cnt1[l - 1] + mod) % mod;
    long long b2 = (cnt2[r] - cnt2[l - 1] + mod) % mod;
    if (a1 != b1 || a2 != b2)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
