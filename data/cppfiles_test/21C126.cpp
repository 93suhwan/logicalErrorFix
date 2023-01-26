#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int n, m, K, p, comb[105][105];
void add(int &a, int b) {
  a += b;
  if (a >= p) a -= p;
}
int dp[105][105][105], fact[105];
int main() {
  scanf("%d%d%d%d", &n, &m, &K, &p);
  comb[0][0] = 1 % p;
  for (int i = 1; i <= n; i++) {
    comb[i][0] = comb[i][i] = 1 % p;
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j - 1];
      add(comb[i][j], comb[i - 1][j]);
    }
  }
  fact[0] = 1 % p;
  for (int i = 1; i <= n; i++) fact[i] = 1LL * i * fact[i - 1] % p;
  for (int i = 0; i <= n; i++) dp[0][0][i] = 1 % p;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= min(i, K); j++)
      for (int k = 0; k <= min(n, m); k++) {
        if (j * 2 > i + 1) continue;
        if (k == 0) {
          if (j == 0) dp[i][j][k] = fact[i];
          continue;
        }
        if (k > i) {
          if (j == 0) dp[i][j][k] = fact[i];
          continue;
        }
        for (int lpos = 0; lpos * 2 <= i - 1; lpos++) {
          int rem = (k == 1 ? j - 1 : j);
          for (int sdkoads = 0; sdkoads <= min(rem, lpos); sdkoads++)
            if (lpos * 2 == i - 1)
              add(dp[i][j][k], 1LL * comb[i - 1][lpos] *
                                   dp[lpos][sdkoads][k - 1] % p *
                                   dp[i - 1 - lpos][rem - sdkoads][k - 1] % p);
            else
              add(dp[i][j][k], 2LL * comb[i - 1][lpos] *
                                   dp[lpos][sdkoads][k - 1] % p *
                                   dp[i - 1 - lpos][rem - sdkoads][k - 1] % p);
        }
      }
  printf("%d\n", dp[n][K][m]);
  return 0;
}
