#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int dp[100005][535];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  dp[0][0] = 0;
  for (int i = 1; i < 535; i++) {
    dp[0][i] = 2e9;
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 535; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    for (int j = 0; j < 535; j++) {
      if (dp[i - 1][j] < arr[i]) {
        dp[i][j ^ arr[i]] = min(dp[i][j ^ arr[i]], arr[i]);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < 535; i++) {
    if (dp[n][i] != 2e9) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  return 0;
}
