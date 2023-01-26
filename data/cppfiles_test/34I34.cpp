#include <bits/stdc++.h>
using namespace std;
int n, a[1000050], dp[5005][8200];
vector<int> b[5005];
int find(int x, int pos) {
  if (!b[x].size()) return -1;
  if (b[x][b[x].size() - 1] < pos) return -1;
  return b[x][lower_bound(b[x].begin(), b[x].end(), pos) - b[x].begin()];
}
int main() {
  memset(dp, 0x3f, sizeof(dp));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]].push_back(i);
  for (int i = 0; i <= 5000; i++) dp[i][0] = 0;
  for (int i = 1; i <= 5000; i++)
    for (int j = 0; j < 8192; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      int pos = find(i, dp[i - 1][j]);
      if (pos != -1) dp[i][j ^ i] = min(dp[i][j ^ i], pos);
    }
  for (int i = 0; i < 8192; i++)
    if (dp[5000][i] <= 1000000) printf("%d ", i);
  return 0;
}
