#include <bits/stdc++.h>
using namespace std;
int dp[105][105][105];
int C[105][105];
int fac[105];
int n, m, k, p;
int dfs(int node, int cnt, int level) {
  int mx = 0;
  if (level <= m) mx = 1 << min(7, (m - level));
  if (cnt > min(node, mx)) return 0;
  if (~dp[node][cnt][level]) return dp[node][cnt][level];
  if (node == 0) return cnt == 0 ? 1 : 0;
  if (node == 1) {
    if (m == level)
      return cnt == 1 ? 1 : 0;
    else
      return cnt == 0 ? 1 : 0;
  }
  if (level == m) {
    return cnt == 1 ? fac[node] : 0;
  }
  int& ans = dp[node][cnt][level];
  ans = 0;
  for (int left = 0; left < node; left++) {
    int right = node - 1 - left;
    int root_yes = level == m ? 1 : 0;
    for (int left_choose = max(0, cnt - right);
         left_choose + root_yes <= min(cnt, left); left_choose++) {
      ans += 1ll * dfs(left, left_choose, level + 1) *
             dfs(right, cnt - root_yes - left_choose, level + 1) % p *
             C[node - 1][left] % p;
      ans %= p;
    }
  }
  return ans;
}
int main(void) {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k >> p;
  fac[0] = 1;
  for (int i = 1; i <= 100; i++) fac[i] = 1ll * fac[i - 1] * i % p;
  C[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  }
  cout << dfs(n, k, 1) << endl;
  return 0;
}
