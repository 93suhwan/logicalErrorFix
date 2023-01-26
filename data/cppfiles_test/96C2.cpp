#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long N = 505;
const long long mod = 998244353;
long long dp[N][N], fac[N];
void init(long long n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}
long long qpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x, long long mod) { return qpow(x, mod - 2, mod); }
long long C(long long n, long long m, long long mod) {
  if (m > n || n < 0 || m < 0) return 0;
  if (n == m || m == 0) return 1;
  if (m > n - m) m = n - m;
  return fac[n] * inv(fac[m], mod) % mod * inv(fac[n - m], mod) % mod;
}
long long dfs(long long n, long long m) {
  if (m < 0) return 1;
  if (n == 1) return 0;
  if (dp[n][m]) return dp[n][m];
  if (m < n) return dp[n][m] = qpow(m, n, mod);
  long long res = 0;
  for (long long i = 0; i <= n; i++)
    (res += C(n, i, mod) * qpow(n - 1, i, mod) % mod * dfs(n - i, m - n + 1) %
            mod) %= mod;
  return dp[n][m] = res;
}
signed main() {
  init(500);
  long long n, m;
  cin >> n >> m;
  cout << dfs(n, m) << endl;
  return 0;
}
