#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int dp[N][N], a[N];
vector<int> inds[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) inds[i].clear();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    inds[a[i]].push_back(i);
  }
  for (int len = 1; len <= n; len++)
    for (int l = 0; l < n; l++) {
      int r = l + len;
      if (r > n) break;
      if (r - l == 1) {
        dp[l][r] = 0;
        continue;
      }
      if (a[r - 1] == a[r - 2]) {
        dp[l][r] = dp[l][r - 1];
        continue;
      }
      dp[l][r] = dp[l][r - 1] + 1;
      for (auto ind : inds[a[r - 1]]) {
        if (ind >= l && ind < r - 1)
          dp[l][r] = min(dp[l][r], dp[l][ind + 1] + dp[ind + 1][r - 1] + 1);
      }
    }
  cout << dp[0][n] << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
