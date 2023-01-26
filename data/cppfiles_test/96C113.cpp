#include <bits/stdc++.h>
using namespace std;
const long long mxi = 501;
long long dp[mxi][mxi];
long long c[mxi][mxi];
long long mod = 998244353;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, x;
  cin >> n >> x;
  for (long long i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (long long i = 1; i <= x; i++) {
    dp[1][x - i] = i;
  }
  for (long long i = 2; i <= n; i++) {
    for (long long j = x - 1; j >= 0; j--) {
      long long um = 1;
      long long to = min(x, j + (i - 1));
      for (long long k = 0; k <= i; k++) {
        long long cc = dp[i - k][to];
        cc *= c[i][k];
        cc %= mod;
        cc *= um;
        cc %= mod;
        dp[i][j] += cc;
        dp[i][j] %= mod;
        um *= (to - j);
        um %= mod;
      }
    }
  }
  long long ans = dp[n][0];
  long long uy = 1;
  for (long long i = 0; i < n; i++) {
    uy *= x;
    uy %= mod;
  }
  cout << (uy - ans + mod) % mod;
}
