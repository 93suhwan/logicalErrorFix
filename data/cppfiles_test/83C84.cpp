#include <bits/stdc++.h>
using namespace std;
int T, n, ans, LCP[5005][5005], dp[5005][5005];
vector<int> vc[5005];
char a[5005];
void slv() {
  scanf("%d %s", &n, a + 1);
  ans = 0;
  for (int i = n, t; i; --i)
    for (int j = n; j > i; --j) {
      t = i < n && j < n ? LCP[i + 1][j + 1] : 0;
      LCP[i][j] = a[i] == a[j] ? t + 1 : 0;
    }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n - i + 1; ++j) vc[j].clear();
    for (int j = 1; j < i; ++j) vc[LCP[j][i]].push_back(j);
    for (int j = 1; j <= n - i + 1; ++j) {
      dp[i][j] = dp[i][j - 1] + 1;
      for (auto k : vc[j - 1])
        if (a[i + j - 1] > a[k + j - 1])
          dp[i][j] = max(dp[i][j], dp[k][n - k + 1] + 1);
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) slv();
  return 0;
}
