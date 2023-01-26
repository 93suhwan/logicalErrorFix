#include <bits/stdc++.h>
using namespace std;
const long long N = 102;
long long mod, M;
long long fac[N], C[N][N], dp[N][N][N];
long long calc(long long n, long long m, long long k) {
  if (k == 0 and m > n) return fac[n];
  if (n == 0) return 0;
  if (m == 1 and k == 1) return fac[n];
  if (m <= 1) return 0;
  if (n - m + 1 < k) return 0;
  if (n - m + 1 + k > n) return 0;
  long long &res = dp[n][m][k];
  if (res != -1) return res;
  res = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j <= k; j++) {
      res += calc(i - 1, m - 1, j) * calc(n - i, m - 1, k - j) % mod *
             C[n - 1][i - 1] % mod;
      res %= mod;
    }
  }
  return res;
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, m, k, p;
  cin >> n >> m >> k >> p;
  mod = p, M = m;
  fac[0] = 1;
  for (long long i = 1; i < N; i++) fac[i] = i * fac[i - 1] % mod;
  C[0][0] = 1;
  for (long long i = 1; i < n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j < n; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  memset(dp, -1, sizeof dp);
  cout << calc(n, m, k);
}
