#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 40;
int f[maxn][maxn];
int dp[maxn];
char s[maxn];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s + 1;
    memset(f, 0, sizeof f);
    for (int i = n; i >= 1; i--)
      for (int j = n; j >= 1; j--) {
        if (s[i] == s[j]) {
          f[i][j] = f[i + 1][j + 1] + 1;
        } else {
          f[i][j] = 0;
        }
      }
    int ans = 0;
    for (int i = 1; i <= n; i++) dp[i] = n - i + 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (s[j] < s[i]) {
          dp[i] = max(dp[i], dp[j] + n - i + 1);
        } else if (s[j] == s[i]) {
          int len = f[i][j];
          if ((i + len - 1) <= n) {
            dp[i] = max(dp[i], dp[j] + n - i + 1 - f[i][j]);
          }
        }
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
