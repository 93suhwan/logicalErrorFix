#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long powmod(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b & 1) {
    return (powmod(a, b - 1) * a) % MOD;
  }
  long long P = powmod(a, b >> 1);
  return (P * P) % MOD;
}
vector<long long> fact;
vector<long long> inv;
long long combs(long long n, long long k) {
  return ((fact[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}
int main() {
  long long n, x;
  cin >> n >> x;
  fact = inv = vector<long long>(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  inv[n] = powmod(fact[n], MOD - 2);
  for (long long i = n - 1; i >= 0; --i) {
    inv[i] = ((i + 1) * inv[i + 1]) % MOD;
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(x + 1));
  for (long long i = 0; i <= x; ++i) {
    dp[0][i] = 1;
  }
  vector<vector<long long>> power(max(n, x) + 1,
                                  vector<long long>(max(n, x) + 1));
  for (long long i = 0; i <= max(n, x); ++i) {
    for (long long j = 0; j <= max(n, x); ++j) {
      if (j == 0) {
        power[i][j] = 1;
      } else {
        power[i][j] = (power[i][j - 1] * i) % MOD;
      }
    }
  }
  for (long long i = 2; i <= n; ++i) {
    for (long long j = 1; j <= x; ++j) {
      if (i > j) {
        dp[i][j] = power[j][i];
        continue;
      }
      for (int cnt = 0; cnt <= i; ++cnt) {
        dp[i][j] += ((dp[cnt][j - i + 1] * power[i - 1][i - cnt]) % MOD *
                     combs(i, cnt)) %
                    MOD;
        if (dp[i][j] >= MOD) {
          dp[i][j] -= MOD;
        }
      }
    }
  }
  cout << dp[n][x];
}
