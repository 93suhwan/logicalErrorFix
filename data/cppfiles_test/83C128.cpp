#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 40;
int f[maxn][maxn];
int dp[maxn];
char s[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    f[n][n + 1] = f[n + 1][n] = f[n + 1][n + 1] = 0;
    for (int i = n; i >= 1; i--)
      for (int j = n; j >= 1; j--) {
        if (s[i] == s[j]) {
          f[i][j] = f[i + 1][j + 1] + 1;
        } else {
          f[i][j] = 0;
        }
      }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; j++) {
        int len = f[i][j];
        if (i + len - 1 >= n || s[i + len] <= s[j + len]) continue;
        dp[i] = max(dp[i], dp[j] + n - i + 1 - len);
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
