#include <bits/stdc++.h>
using namespace std;
const int NR = 105;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, k, mod;
int fac[NR], C[NR][NR];
int dp[NR][NR][NR];
void init() {
  fac[0] = 1;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) C[i][0] = C[i][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  C[0][0] = 1;
}
int dfs(int x, int num, int now) {
  if (dp[x][num][now] != -1) return dp[x][num][now];
  if (x == 0) return dp[x][num][now] = 1;
  if (m - now < 7 && (1 << (m - now)) < num || (num && x < m - now))
    return dp[x][num][now] = 0;
  if (now == m) return dp[x][num][now] = (num == 1 ? fac[x] : 0);
  int ans = 0;
  for (int i = 0; i < x; i++) {
    int F = 0;
    for (int j = max(0, num + i + 1 - x); j <= min(num, i); j++) {
      F = (F +
           1ll * dfs(i, j, now + 1) * dfs(x - i - 1, num - j, now + 1) % mod) %
          mod;
    }
    ans = (ans + 1ll * F * C[x - 1][i]) % mod;
  }
  return dp[x][num][now] = ans;
}
int main() {
  n = read(), m = read(), k = read(), mod = read();
  init();
  m--;
  printf("%d\n", dfs(n, k, 0));
  return 0;
}
