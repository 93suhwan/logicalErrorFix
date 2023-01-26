#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int> > pos(n);
    for (int i = 0; i < (int)n; i++) {
      cin >> nums[i];
      nums[i] -= 1;
      pos[nums[i]].push_back(i);
    }
    vector<vector<int> > dp(n + 1, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < (int)n; j++) {
        dp[i][j] = (dp[i + 1][j] + (nums[i] != nums[j]));
        for (auto k : pos[nums[i]]) {
          if (k > j) break;
          if (k < i) continue;
          int temp = dp[i][k] + 1 + dp[k + 1][j];
          dp[i][j] = min(dp[i][j], temp);
        }
      }
    }
    cout << dp[0][n - 1] << '\n';
  }
}
