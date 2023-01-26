#include <bits/stdc++.h>
using namespace std;
int t, n, ans, lcp[5009][5009], dp[5009];
string a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a;
    ans = 0;
    for (int i = n - 1; i > 0; i--)
      for (int j = n - 1; j > 0; j--)
        lcp[i][j] = (a[i] == a[j]) ? (lcp[i + 1][j + 1] + 1) : 0;
    for (int i = 0; i < n; i++) {
      dp[i] = (n - 1) + 1 - i;
      for (int j = 0; j < i; j++) {
        int len = lcp[i][j];
        if (a[j + len] < a[i + len])
          dp[i] = max(dp[i], dp[j] + n + 1 - (i + len));
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
