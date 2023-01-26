#include <bits/stdc++.h>
using namespace std;
const int mxN = 2000;
int dp[mxN + 1][mxN + 1], a[mxN + 1];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
      if (i - a[i] == j) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
    }
  }
  for (int j = 0; j < n + 1; j++) {
    if (dp[n][j] >= k) {
      cout << j << '\n';
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin >> TC;
  while (TC--) solve();
}
