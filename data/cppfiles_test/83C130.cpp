#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[5005];
int dp[5005];
int a[5005][5005];
int ans;
void sol() {
  cin >> n;
  scanf("%s ", s + 1);
  ans = n;
  for (int i = 1; i <= n + 1; ++i)
    for (int j = i + 1; j <= n + 1; ++j) a[i][j] = 0;
  s[n + 1] = 'a' - 1;
  for (int i = n; i >= 1; --i)
    for (int j = i + 1; j <= n; ++j)
      if (s[i] != s[j])
        a[i][j] = 0;
      else
        a[i][j] = a[i + 1][j + 1] + 1;
  dp[1] = n;
  for (int i = 2; i <= n; ++i) {
    dp[i] = n - i + 1;
    for (int j = 1; j < i; ++j) {
      int k = a[j][i];
      if (s[i + k] - 'a' > s[j + k] - 'a')
        dp[i] = max(dp[i], dp[j] + n - i + 1 - k);
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}
int main() {
  cin >> t;
  while (t--) sol();
}
