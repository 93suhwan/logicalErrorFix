#include <bits/stdc++.h>
using namespace std;
long long int dp[2005][2005];
long long int minsteps(long long int i, long long int j, long long int k,
                       vector<long long int>& arr) {
  if (k == 0) {
    return 0;
  }
  if (i == arr.size()) {
    return INT_MAX;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  long long int index = i - j + 1;
  if (arr[i] == index) {
    dp[i][j] = minsteps(i + 1, j, k - 1, arr);
    return dp[i][j];
  }
  long long int ans1 = 1 + minsteps(i + 1, j + 1, k, arr);
  long long int ans2 = minsteps(i + 1, j, k, arr);
  dp[i][j] = min(ans1, ans2);
  return dp[i][j];
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = -1;
    }
  }
  vector<long long int> arr;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    arr.push_back(x);
  }
  long long int ans = minsteps(0, 0, k, arr);
  if (ans >= 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
