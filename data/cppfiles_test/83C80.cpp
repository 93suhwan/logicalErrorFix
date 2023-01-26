#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const int maxn = 5010;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    static char s[maxn];
    scanf("%s", s);
    static int lcp[maxn][maxn];
    for (int i = 0; i <= n; ++i) {
      lcp[0][n] = lcp[n][0] = 0;
    }
    int ans = 0;
    static int dp[maxn];
    for (int i = n - 1; i >= 0; --i) {
      dp[i] = n - i;
      for (int j = i + 1; j < n; ++j) {
        lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
        int len = lcp[i][j];
        if (len != n - j && s[i + len] < s[j + len]) {
          dp[i] = max(dp[i], dp[j] + (n - i) - len);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
