#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
int c[105][105], dp[105][105][105];
int fac[105];
int dfs(int i, int j, int dep) {
  if (i < j) return 0;
  if (i == 0 && j == 0) return 1;
  if (i == 0) return 1;
  if (j && i - (m - dep) < j) return 0;
  if (dp[i][j][dep] != -1) return dp[i][j][dep];
  if (dep == m) return (j == 1) ? fac[i] : 0;
  int ans = 0, t1, t2;
  for (int l = 0; l < i; l++) {
    for (int j1 = 0; j1 <= j; j1++) {
      t1 = dfs(l, j1, dep + 1);
      if (t1) t2 = dfs(i - 1 - l, j - j1, dep + 1);
      if (t1 && t2) ans = (ans + (long long)c[i - 1][l] * t1 % p * t2 % p) % p;
    }
  }
  return dp[i][j][dep] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> p;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = (long long)fac[i - 1] * i % p;
  }
  for (int i = 0; i <= n; i++) c[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(n, k, 1) << endl;
  return 0;
}
