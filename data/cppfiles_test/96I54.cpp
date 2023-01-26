#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long binpow(long long n, long long k) {
  if (k == 0) {
    return 1;
  }
  if (k % 2) {
    return binpow(n, k - 1) * n % mod;
  }
  return binpow(n * n % mod, k / 2) % mod;
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long dp[n + 1][k + 1];
  for (int j = 1; j <= k; ++j) {
    dp[1][j] = j;
  }
  long long proiz[n + 1][n + 1];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      proiz[i][j] = 1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = i; j <= n; ++j) {
      proiz[i][j] = (proiz[i][j - 1] * j) % mod;
    }
  }
  long long fack[n + 1];
  long long ifack[n + 1];
  fack[0] = 1;
  ifack[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    fack[i] = fack[i - 1] * i % mod;
    ifack[i] = binpow(fack[i], mod - 2);
  }
  long long powr[n + 1][n + 1];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      powr[i][j] = 1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j) {
      powr[i][j] = (powr[i][j - 1] * i) % mod;
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = 0;
      if (j >= i) {
        for (int z = 1; z <= i; ++z) {
          long long kumer;
          if (z != i)
            kumer = proiz[z + 1][i];
          else
            kumer = 1;
          long long perest_umer = ifack[i - z];
          if (i == 3 && j == 5) {
          }
          long long umer = kumer * perest_umer % mod;
          long long func = powr[i - 1][i - z] * umer % mod;
          func = func * dp[z][j - i + 1] % mod;
          dp[i][j] += func;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
    }
  }
  long long res = 1;
  for (int i = 1; i <= n; ++i) {
    res *= k;
    res %= mod;
  }
  long long ans = ((res - dp[n][k]) % mod + mod) % mod;
  cout << ans << "\n";
  return 0;
}
