#include <bits/stdc++.h>
using namespace std;
long long dp[505][505], po[505][505], c[505][505];
long long solve(long long n, long long x) {
  if (n == 0) return dp[n][x] = 1;
  if (n == 1) return dp[n][x] = 0;
  if (x < 1) return dp[n][x] = 0;
  if (x < n) return dp[n][x] = po[x][n];
  long long &ret = dp[n][x];
  if (ret != -1) return ret;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long o = (po[n - 1][i] * c[n][i]) % 998244353;
    ans = (ans + (solve(n - i, x - (n - 1)) * o) % 998244353) % 998244353;
  }
  return ret = ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(dp, -1, sizeof(dp));
  c[0][0] = 1;
  for (long long i = 1; i <= 500; i++) {
    po[i][0] = 1;
    c[i][0] = 1;
    for (long long j = 1; j <= 500; j++) {
      if (j <= i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 998244353;
      po[i][j] = (i * po[i][j - 1]) % 998244353;
    }
  }
  long long n, x;
  cin >> n >> x;
  long long ans = 0;
  cout << solve(n, x) << "\n";
  return 0;
}
