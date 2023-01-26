#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
int a[maxn];
int pre[maxn];
int last[maxn];
int dp[maxn][maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int tot;
    cin >> tot;
    int n = 1;
    for (int i = (0); i < (tot + 1); ++i) last[i] = 0;
    for (int i = (1); i < (tot + 1); ++i) {
      scanf("%d", &a[n]);
      if (a[n] == a[n - 1]) continue;
      pre[n] = last[a[n]];
      last[a[n]] = n;
      n++;
    }
    n--;
    int ans = n - 1;
    for (int i = (1); i < (n + 1); ++i)
      for (int j = (i); j < (n + 1); ++j) dp[i][j] = 0;
    for (int len = (2); len < (n + 1); ++len) {
      for (int l = 1; l + len - 1 <= n; ++l) {
        int r = l + len - 1;
        dp[l][r] = dp[l][r - 1];
        for (int p = pre[r]; p >= l; p = pre[p]) {
          dp[l][r] = max(dp[l][r], dp[l][p] + dp[p][r - 1] + 1);
        }
      }
    }
    ans -= dp[1][n];
    cout << ans << endl;
  }
  return 0;
}
