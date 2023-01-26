#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 200020;
long long n, m, dx[maxn], dy[maxn], fac[maxn << 1], inv[maxn << 1],
    inv2[maxn << 1];
bool mrk[maxn];
long long C(long long x, long long y) {
  return (x < 0 || y < 0 || x < y)
             ? 0
             : (fac[x] * ((inv2[y] * inv2[x - y]) % mod)) % mod;
}
int main() {
  long long t, tot;
  fac[0] = fac[1] = inv[1] = inv2[0] = inv2[1] = 1;
  for (int i = 2; i < (maxn << 1); i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = (mod - (((mod / i) * inv[mod % i]) % mod)) % mod;
    inv2[i] = (inv2[i - 1] * inv[i]) % mod;
  }
  scanf("%lld", &t);
  for (int testcases = 0; testcases < t; testcases++) {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) scanf("%lld%lld", &dx[i], &dy[i]);
    memset(mrk, false, sizeof(mrk));
    int j = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
      if (j < m && i == dx[j]) {
        if (!mrk[dy[j] - 1]) tot++;
        mrk[dy[j] - 1] = false;
        for (int k = m; k > dy[j]; k--) mrk[k] = mrk[k - 1];
        mrk[dy[j]] = true;
        j++;
      }
    }
    printf("%lld\n", C(n + n - tot - 1, n));
  }
  return 0;
}
