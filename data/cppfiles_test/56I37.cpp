#include <bits/stdc++.h>
using namespace std;
const long long NR = 2e3 + 5;
const long long MR = 65;
const long long MOD = 1e9 + 7;
char s[10];
long long lsh[NR * MR];
long long v[NR], co[NR];
long long dp[NR * MR][7];
long long col[NR * MR];
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    b >>= 1, a = a * a % MOD;
  }
  return res;
}
int main() {
  long long m, n;
  scanf("%lld%lld", &m, &n);
  long long cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", v + i);
    long long x = v[i];
    scanf("%s", s + 1);
    if (s[1] == 'w')
      co[i] = 0;
    else if (s[1] == 'o')
      co[i] = 1;
    else if (s[1] == 'g')
      co[i] = 2;
    else if (s[1] == 'b')
      co[i] = 3;
    else if (s[1] == 'r')
      co[i] = 4;
    else
      co[i] = 5;
    while (x) {
      lsh[++cnt] = x;
      x /= 2;
    }
  }
  sort(lsh + 1, lsh + cnt + 1);
  cnt = unique(lsh + 1, lsh + cnt + 1) - lsh - 1;
  memset(col, -1, sizeof(col));
  for (long long i = 1; i <= n; ++i) {
    long long x = lower_bound(lsh + 1, lsh + cnt + 1, v[i]) - lsh;
    dp[x][co[i]] = 1;
    col[x] = co[i];
  }
  for (long long i = 0; i < 6; ++i) dp[cnt + 1][i] = 1;
  for (long long i = cnt; i >= 1; --i) {
    long long x = lsh[i];
    long long y = lower_bound(lsh + 1, lsh + cnt + 1, x * 2) - lsh;
    long long z = lower_bound(lsh + 1, lsh + cnt + 1, x * 2 + 1) - lsh;
    if (lsh[y] != x * 2) y = cnt + 1;
    if (lsh[z] != x * 2 + 1) z = cnt + 1;
    if (y == cnt + 1 && z == cnt + 1) continue;
    for (long long j = 0; j < 6; ++j) {
      dp[i][j] = 0;
      if ((~col[i]) && col[i] != j) continue;
      for (long long k = 0; k < 6; ++k) {
        if (dp[y][k] == 0) continue;
        if (k + j == 5 || k == j) continue;
        for (long long l = 0; l < 6; ++l) {
          if (l + j == 5 || l == j) continue;
          (dp[i][j] += dp[y][k] * dp[z][l] % MOD) %= MOD;
        }
      }
      if (y == cnt + 1 || z == cnt + 1) dp[i][j] /= 4;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 6; ++i) ans = (ans + dp[1][i]) % MOD;
  ans = ans * ksm(4, (1ll << m) - 1 - cnt) % MOD;
  printf("%lld\n", ans);
  return 0;
}
