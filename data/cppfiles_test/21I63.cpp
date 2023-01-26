#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p;
long long dp[105][105][105];
long long c[105][105];
long long dfs(long long cur, long long num, long long dep) {
  if (num < 0 || cur < num || (dep > m && num > 0)) return 0;
  if (cur == 0) return 1;
  if (dp[cur][num][dep] != -1) return dp[cur][num][dep];
  dp[cur][num][dep] = 0LL;
  for (int i = 0; i < cur; i++) {
    for (int j = 0; j <= num; j++) {
      long long temp = c[cur - 1][i];
      temp = temp * dfs(i, j, dep + 1) % p;
      if (temp == 0) break;
      temp = temp * dfs(cur - i - 1, num - j - (dep == m), dep + 1) % p;
      dp[cur][num][dep] = (dp[cur][num][dep] + temp) % p;
    }
  }
  return dp[cur][num][dep];
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%lld%lld%lld%lld", &n, &m, &k, &p);
  for (int i = 0; i <= n; i++) c[i][0] = 1LL;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  printf("%lld\n", dfs(n, k, 1));
  return 0;
}
