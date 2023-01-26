#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e2 + 7;
const long long maxm = 2e5 + 7;
const long long inf = 0x3f3f3f3f;
const long long mod = 998244353;
long long FastPowerMod(long long x, long long n) {
  if (!n) return 1;
  long long t = 1;
  while (n) {
    if (n & 1) t *= x;
    n >>= 1;
    x *= x;
    x = (x + mod) % mod;
    t = (t + mod) % mod;
  }
  return t;
}
long long dp[maxn][maxn];
long long yh[510][510];
long long dfs(long long n, long long x) {
  if (n <= 1) return 0;
  if (dp[n][x] != 0) {
    return dp[n][x];
  }
  if (n - 1 >= x) {
    dp[n][x] = FastPowerMod(x, n);
    dp[n][x] %= mod;
    return dp[n][x];
  } else {
    long long sum = 0;
    for (long long i = 2; i <= n; i++) {
      long long t = FastPowerMod(n - 1, n - i);
      sum += t * dfs(i, x - n + 1) * yh[n][i];
      sum %= mod;
    }
    sum += FastPowerMod(n - 1, n);
    sum %= mod;
    dp[n][x] = sum % mod;
    return sum % mod;
  }
}
signed main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 0; i <= 500; i++) {
    for (long long j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        yh[i][j] = 1;
      } else {
        yh[i][j] = (yh[i - 1][j - 1] + yh[i - 1][j]) % 998244353;
      }
    }
  }
  long long a, b;
  cin >> a >> b;
  cout << (dfs(a, b) + mod) % mod << endl;
  return (0);
}
