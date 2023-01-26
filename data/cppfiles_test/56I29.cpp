#include <bits/stdc++.h>
using namespace std;
const int NR = 2e3 + 5;
const int MR = 65;
const int MOD = 1e9 + 7;
char s[10];
int lsh[NR * MR];
int v[NR], co[NR];
int dp[NR * MR][7];
int col[NR * MR];
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    b >>= 1, a = a * a % MOD;
  }
  return res;
}
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    int x = v[i];
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
  for (int i = 1; i <= n; ++i) {
    int x = lower_bound(lsh + 1, lsh + cnt + 1, v[i]) - lsh;
    dp[x][co[i]] = 1;
    col[x] = co[i];
  }
  for (int i = cnt; i > 1; --i) {
    int x = lsh[i];
    int y = lower_bound(lsh + 1, lsh + cnt + 1, x / 2) - lsh;
    for (int j = 0; j < 6; ++j) dp[y][j] = 0;
    for (int j = 0; j < 6; ++j)
      for (int k = 0; k < 6; ++k) {
        if (j == k || j + k == 5) continue;
        if ((~col[y]) && col[y] != k) continue;
        (dp[y][k] += dp[i][j]) % MOD;
      }
  }
  long long ans = 0;
  for (int i = 0; i < 6; ++i) ans = (ans + dp[1][i]) % MOD;
  ans = ans * ksm(4, (1ll << m) - 1 - cnt) % MOD;
  printf("%lld\n", ans);
  return 0;
}
