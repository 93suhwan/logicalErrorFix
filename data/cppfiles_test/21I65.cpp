#include <bits/stdc++.h>
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
void die(string S) {
  puts(S.c_str());
  exit(0);
}
long long dp[110][110][110];
long long p;
long long C[110][110];
long long calc(long long i, long long j, long long kk) {
  if (dp[i][j][kk] != -1) return dp[i][j][kk];
  if (j + kk > i + 40) return 0;
  if (j <= 1) return 0;
  dp[i][j][kk] = 0;
  for (register int l = 1; l <= i; l++)
    for (register int o = 0; o <= kk; o++)
      dp[i][j][kk] =
          (dp[i][j][kk] + calc(l - 1, j - 1, o) * calc(i - l, j - 1, kk - o) %
                              p * C[i - 1][l - 1]) %
          p;
  return dp[i][j][kk];
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, m, k;
  cin >> n >> m >> k >> p;
  C[0][0] = 1;
  for (int i = 1; i < 110; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
  }
  for (int i = 0; i < 110; i++) dp[0][i][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][1][1] = 1;
    for (int j = 1; j <= i; j++) dp[i][1][1] = dp[i][1][1] * j % p;
  }
  cout << calc(n, m, k) << endl;
  return 0;
}
