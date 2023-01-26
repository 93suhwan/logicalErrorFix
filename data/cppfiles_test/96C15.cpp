#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int add(long long x, long long y) { return (x + y) % MOD; }
int sub(long long x, long long y) { return add(x, MOD - y); }
int mul(long long x, long long y) { return (x * y) % MOD; }
int bp(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
int inv(int x) { return bp(x, MOD - 2); }
const int MXN = 510;
int fact[MXN], invf[MXN];
int chs(int n, int k) {
  if (n <= k) return n == k;
  return mul(fact[n], mul(invf[k], invf[n - k]));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  invf[0] = inv(fact[0]);
  for (int i = 1; i < MXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    invf[i] = inv(fact[i]);
  }
  int p[MXN][MXN];
  for (int i = 0; i < MXN; i++) {
    p[i][0] = 1;
    for (int j = 1; j < MXN; j++) {
      p[i][j] = mul(p[i][j - 1], i);
    }
  }
  int n, m;
  cin >> n >> m;
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j < i) dp[i][j] = add(dp[i][j], sub(p[j][i], p[j - 1][i]));
      for (int k = 0; i + k <= n && j + i + k - 1 <= m; k++) {
        dp[i + k][j + i + k - 1] =
            add(dp[i + k][j + i + k - 1],
                mul(dp[i][j], mul(chs(i + k, k), p[i + k - 1][k])));
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    ans = add(ans, dp[n][j]);
  }
  cout << ans << '\n';
}
