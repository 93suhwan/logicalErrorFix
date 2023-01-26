#include <bits/stdc++.h>
using namespace std;
bool pos(vector<int> &arr, int m, int n) {
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
  for (int j = 0; j <= m; j++) dp[0][j] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j - arr[i - 1] >= 0 && dp[i - 1][j - arr[i - 1]]) dp[i][j] = true;
      if (j + arr[i - 1] <= m && dp[i - 1][j + arr[i - 1]]) dp[i][j] = true;
    }
  }
  for (int j = 0; j <= m; j++)
    if (dp[n][j]) return true;
  return false;
}
int solve() {
  int n, mx = 0;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  int res = 2 * mx, low = mx, high = 2 * mx;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (pos(arr, mid, n)) {
      res = min(res, mid);
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) cout << solve() << "\n";
  return 0;
}
