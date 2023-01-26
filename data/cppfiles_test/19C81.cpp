#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &it : arr) {
    cin >> it;
  }
  vector<vector<int> > dp(2, vector<int>(2 * 1000 + 1, INT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int p = i & 1;
    for (int j = 0; j <= 2 * 1000; ++j) {
      dp[p ^ 1][j] = INT_MAX;
    }
    for (int j = 0; j <= 2 * 1000; ++j) {
      if (dp[p][j] == INT_MAX) {
        continue;
      }
      if (j + arr[i] <= 2 * 1000) {
        dp[p ^ 1][j + arr[i]] =
            min(dp[p ^ 1][j + arr[i]], max(dp[p][j] - arr[i], 0));
      }
      dp[p ^ 1][max(j - arr[i], 0)] =
          min(dp[p ^ 1][max(j - arr[i], 0)], dp[p][j] + arr[i]);
    }
  }
  int sol = INT_MAX;
  for (int i = 0; i <= 2 * 1000; ++i) {
    if (dp[n & 1][i] == INT_MAX) {
      continue;
    }
    sol = min(sol, dp[n & 1][i] + i);
  }
  cout << sol << "\n";
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
