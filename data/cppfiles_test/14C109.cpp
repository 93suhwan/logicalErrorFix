#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int> > dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        dp[i][j] = dp[i - 1][j];
        if (i - j == a[i]) {
          dp[i][j]++;
        }
        if (j > 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
