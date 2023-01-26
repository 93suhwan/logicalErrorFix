#include <bits/stdc++.h>
const int N = 1000100;
int n, k, a, dp[2][N], ans[N], cur;
std::vector<int> v[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 8192; ++i) dp[cur][i] = dp[cur ^ 1][i] = n + 1;
  dp[cur][0] = 0, k = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a), v[a].push_back(i);
  for (int i = 0; i < 5000; ++i, cur ^= 1) {
    for (int j = 0; j < 8192; ++j) dp[cur ^ 1][j] = dp[cur][j];
    if (!v[i + 1].size()) continue;
    for (int j = 0; j < 8192; ++j) {
      if (dp[cur][j] == n + 1) continue;
      int id = std::lower_bound(v[i + 1].begin(), v[i + 1].end(), dp[cur][j]) -
               v[i + 1].begin();
      if (id == v[i + 1].size()) continue;
      dp[cur ^ 1][j ^ (i + 1)] =
          std::min(dp[cur ^ 1][j ^ (i + 1)], v[i + 1][id]);
    }
  }
  for (int i = 0; i < 8192; ++i)
    if (dp[cur][i] != n + 1) ans[++k] = i;
  printf("%d\n", k);
  for (int i = 1; i <= k; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
