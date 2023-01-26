#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int maxn = 1e5 + 5;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &u : a) cin >> u;
  vector<vector<int>> dp(n, vector<int>(n + 1, -1e9));
  dp[0][1] = (a[0] == 1);
  dp[0][0] = 0;
  for (int i = 1; i < n; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i - 1][j - 1] != -1e9)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + int(a[i] == j));
    }
  }
  for (int i = n; i >= 1; i--) {
    if (dp[n - 1][i] >= k) {
      cout << n - i;
      return;
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
