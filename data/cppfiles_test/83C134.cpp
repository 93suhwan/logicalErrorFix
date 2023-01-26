#include <bits/stdc++.h>
using namespace std;
int t, n, ans, dp[5005], lcp[5005][5005];
char s[5005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &n, s + 1);
    for (int i = n; i >= 1; --i) {
      dp[i] = 0;
      for (int j = n; j >= 1; --j) {
        if (s[i] == s[j])
          lcp[i][j] = lcp[i + 1][j + 1] + 1;
        else
          lcp[i][j] = 0;
      }
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[j] - lcp[i][j] > dp[i] && s[j + lcp[i][j]] < s[i + lcp[i][j]])
          dp[i] = dp[j] - lcp[i][j];
      }
      dp[i] += n - i + 1;
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
