#include <bits/stdc++.h>
using namespace std;
int solve(const vector<int>& a, int k) {
  int n = a.size();
  vector<vector<int>> dp(n);
  vector<int>{a[0] == 0, 0}.swap(dp[0]);
  for (int i = 1; i < n; ++i) {
    vector<int>(i + 2, 0).swap(dp[i]);
    for (int j = 0; j <= i + 1; ++j) {
      if (j > 0) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      if (j < i + 1) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == (i - j)));
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (dp[n - 1][i] >= k) return i;
  }
  return -1;
}
void test_case() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  cout << solve(a, k) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test_case();
  }
}
