#include <bits/stdc++.h>
using namespace std;
int lcp[5042][5042], dp[5042];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= n; i++) lcp[i][n] = 0;
    for (int i = n - 1; i >= 0; i--)
      for (int j = i; j >= 0; j--)
        if (s[i] == s[j])
          lcp[j][i] = 1 + lcp[j + 1][i + 1];
        else
          lcp[j][i] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int il = n - i;
      dp[i] = il;
      for (int j = 0; j < i; j++) {
        int lp = lcp[j][i];
        char sjlp = s[j + lp];
        if (i + lp == n) continue;
        char silp = s[i + lp];
        if (sjlp < silp) dp[i] = max(dp[i], il - lp + dp[j]);
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
