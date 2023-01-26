#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] -= i;
  }
  vector<vector<int> > dp(n + 1);
  for (int i = 0; i <= n; i++) dp[i].resize(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[j][i] = dp[j][i - 1];
      if (v[i] == -j) dp[j][i]++;
      if (j != 0) dp[j][i] = max(dp[j][i], dp[j - 1][i - 1]);
    }
  }
  int ans = -1;
  for (int i = 0; i <= n; i++) {
    if (dp[i][n] >= k) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int z;
  cin >> z;
  while (z--) solve();
  return 0;
}
