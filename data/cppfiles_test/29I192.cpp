#include <bits/stdc++.h>
using namespace std;
int solve(int n, int arr[], int sum) {
  int dp[n + 1][sum + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (i == 0) dp[i][j] = 0;
      if (j == 0) dp[i][j] = 1;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j)
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) sum += a[i];
    int summ = sum - 1;
    int ans = solve(n, a, summ);
    if (sum == 1)
      cout << ans + 1 << endl;
    else
      cout << ans << endl;
  }
}
