#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int t, n, ans;
int dp[N], lcp[N][N];
char s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) lcp[i][j] = 0;
    for (int i = n; i; --i)
      for (int j = i + 1; j <= n; ++j)
        if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    for (int i = 1; i <= n; ++i) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; ++j) {
        int k = lcp[j][i];
        if (s[j + k] < s[i + k]) dp[i] = max(dp[i], dp[j] + n - i - k + 1);
      }
    }
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    printf("%d\n", ans);
  }
  return 0;
}
