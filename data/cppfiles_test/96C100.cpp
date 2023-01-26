#include <bits/stdc++.h>
using namespace std;
const long long tdh = 998244353;
const long long N = 510;
long long ksm(long long a, long long b) {
  long long ans = 1;
  a %= tdh;
  while (b) {
    if (b & 1) ans = ans * a % tdh;
    a = (a * a) % tdh;
    b >>= 1;
  }
  return ans % tdh;
}
inline long long read() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
long long f[N * 2][N];
long long jc_inv[N + 1], jc[N + 1];
long long C(long long n, long long m) {
  if (m > n) return 0;
  return jc[n] * jc_inv[m] % tdh * jc_inv[n - m] % tdh;
}
signed main() {
  ios::sync_with_stdio(false);
  long long i, j, k, n, m;
  jc[0] = 1;
  for (i = 1; i <= N; i++) jc[i] = jc[i - 1] * i % tdh;
  jc_inv[N] = ksm(jc[N], tdh - 2);
  for (i = N - 1; i >= 1; i--) jc_inv[i] = jc_inv[i + 1] * (i + 1) % tdh;
  long long ans = 0;
  cin >> n >> m;
  f[1][n] = 1;
  for (i = 1; i < m; i++) {
    if (i != 1) ans = (ans + f[i][1] * (m - i + 1)) % tdh;
    for (j = 2; j <= n; j++)
      if (f[i][j]) {
        f[i + j - 1][j] = (f[i][j] + f[i + j - 1][j]) % tdh;
        for (k = 1; k < j; k++) {
          f[i + j - 1][k] = (C(j, k) * ksm(j - 1, j - k) % tdh * f[i][j] % tdh +
                             f[i + j - 1][k]) %
                            tdh;
        }
      }
  }
  ans += f[m][1];
  ans %= tdh;
  cout << (ksm(m, n) - ans + tdh) % tdh << endl;
  return 0;
}
