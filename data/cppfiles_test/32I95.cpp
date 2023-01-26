#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> pref(n + 1);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
  vector<vector<long long>> dp(n, vector<long long>(350, -1));
  for (int i = 0; i < n; i++) dp[i][1] = a[i];
  for (int i = n - 2; i >= 0; i--) {
    dp[i][1] = max(dp[i + 1][1], dp[i][1]);
  }
  for (int j = 2; j < 350; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (dp[i][j - 1] != -1 && i >= j) {
        long long sum = pref[i] - pref[i - j];
        if (sum < dp[i][j - 1]) {
          if (dp[i - j][j] == -1)
            dp[i - j][j] = sum;
          else
            dp[i - j][j] = max(dp[i - j][j], sum);
        }
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      dp[i][j] = max(dp[i + 1][j], dp[i][j]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 350; j++) {
      if (dp[i][j] != -1) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
