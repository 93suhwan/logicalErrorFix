#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx", "sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long N = 105;
long long dp[N][N][N];
long long c[N][N];
long long p;
long long add(const long long &a, const long long &b) {
  long long ret = a + b;
  if (ret < p) return ret;
  return ret - p;
}
long long mul(const long long &a, const long long &b) { return (a * b) % p; }
signed main(signed argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m, k;
  cin >> n >> m >> k >> p;
  for (long long i = 0; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
    }
  }
  dp[1][0][0] = 1;
  long long val = 1;
  for (long long i = 1; i <= n; i++) {
    val = mul(val, i);
    dp[1][i][1] = val;
  }
  for (long long M = 1; M < m; M++) {
    for (long long L = 0; L < n; L++) {
      for (long long k1 = 0; k1 < k + 1; k1++) {
        if (!dp[M][L][k1]) continue;
        for (long long R = 0; R < n - L; R++) {
          for (long long k2 = 0; k2 < k - k1 + 1; k2++) {
            if (!dp[M][R][k2]) continue;
            dp[M + 1][L + R + 1][k1 + k2] =
                add(dp[M + 1][L + R + 1][k1 + k2],
                    mul(c[L + R][L], mul(dp[M][L][k1], dp[M][R][k2])));
          }
        }
      }
    }
    dp[M + 1][0][0] = 1;
  }
  cout << dp[m][n][k];
}
