#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e2 + 7;
const long long maxm = 2e5 + 7;
const long long inf = 0x3f3f3f3f;
const unsigned long long mod = 998244353;
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
unsigned long long dp[maxn][maxn];
unsigned long long yh[510][510];
unsigned long long dfs(unsigned long long n, unsigned long long x) {
  if (n <= 1) return 0;
  if (dp[n][x] != 0) {
    return dp[n][x];
  }
  if (n - 1 >= x) {
    dp[n][x] = FastPowerMod(x, n);
    dp[n][x] %= mod;
    return dp[n][x];
  } else {
    unsigned long long sum = 0;
    for (unsigned long long i = 2; i <= n; i++) {
      unsigned long long t = FastPowerMod(n - 1, n - i);
      sum = (sum + t % mod * dfs(i, x - n + 1) % mod * yh[n][i]) % mod;
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
  for (unsigned long long i = 0; i <= 500; i++) {
    for (unsigned long long j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        yh[i][j] = 1;
      } else {
        yh[i][j] = (yh[i - 1][j - 1] + yh[i - 1][j]) % 998244353;
      }
    }
  }
  unsigned long long a, b;
  cin >> a >> b;
  cout << (dfs(a, b) + mod) % mod << endl;
  return (0);
}
