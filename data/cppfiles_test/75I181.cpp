#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums[i] = temp;
  }
  vector<vector<int>> max_nums(n, vector<int>(n));
  max_nums[0][n - 1] = -1;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      max_nums[i][n - 1] = max(max_nums[i - 1][n - 1], nums[i - 1]);
    }
    for (int j = n - 2; j >= i; --j) {
      max_nums[i][j] = max(max_nums[i][j + 1], nums[j + 1]);
    }
  }
  vector<vector<bool>> dp(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    if (nums[i] > max_nums[i][i]) {
      dp[i][i] = true;
    } else {
      dp[i][i] = false;
    }
  }
  for (int m = 1; m < n; ++m) {
    for (int i = 0; i + m < n; ++i) {
      int j = i + m;
      if (nums[i] > max_nums[i + 1][j] && !dp[i + 1][j]) {
        dp[i][j] = true;
        continue;
      }
      if (nums[j] > max_nums[i][j - 1] && !dp[i][j - 1]) {
        dp[i][j] = true;
        continue;
      }
      dp[i][j] = false;
    }
  }
  if (dp[0][n - 1]) {
    cout << "Alice";
    return 0;
  }
  cout << "Bob";
  return 0;
}
