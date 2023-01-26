#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, K;
long long f[110][2010], g[110][2010], res[4040], pre[4040];
long long b[10000];
long long F[10000], Finv[10000];
inline long long qpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int32_t main() {
  Finv[0] = F[0] = 1;
  for (long long i = 1; i <= 8000; i++)
    F[i] = F[i - 1] * i % mod, Finv[i] = qpow(F[i], mod - 2);
  ios::sync_with_stdio(false);
  cin >> n >> K;
  for (long long i = 1; i <= n; i++) cin >> b[i];
  f[K + 1][0] = 1;
  for (long long i = 1; i <= n; i++) {
    memset(res, 0, sizeof(res));
    memset(pre, 128, sizeof(res));
    for (long long d = -K; d <= K; d++) {
      long long j = b[i] + d, id = d + K + 1;
      if (j < 0 || j > n) continue;
      for (long long k = 0; k <= n; k++) {
        if (abs(b[i - 1] - j) <= K) {
          g[id][k] = f[j - b[i - 1] + K + 1][k] * (j + k);
          if (k) {
            g[id][k] += f[j - b[i - 1] + K + 1][k - 1];
          }
          g[id][k] %= mod;
        }
        long long ret = 0;
        if (pre[j + k] < -K) pre[j + k] = -K;
        for (long long T = pre[j + k]; T <= K; T++) {
          long long t = b[i - 1] + T, it = T + K + 1;
          if (t < 0) continue;
          pre[j + k] = T;
          if (t >= j) break;
          (res[j + k] += f[it][k + (j - t - 1)] * F[k + j - t - 1]) %= mod;
          if (T == K) pre[j + k] = K + 1;
        }
        g[id][k] += res[j + k] * Finv[k];
        g[id][k] %= mod;
      }
    }
    memcpy(f, g, sizeof(g));
    memset(g, 0, sizeof(g));
  }
  long long ret = 0;
  for (long long d = -K; d <= K; d++) {
    long long j = b[n] + d, id = d + K + 1;
    for (long long k = 0; k <= n; k++) {
      if (n - j - k >= 0)
        ret += f[id][k] * F[n - j] % mod * Finv[n - j - k], ret %= mod;
    }
  }
  cout << ret;
}
