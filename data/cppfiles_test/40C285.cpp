#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e10 + 5;
void solve() {
  long long int m;
  cin >> m;
  long long int grid[2][m], dp[2][m];
  for (long long int i = 0; i < 2; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  dp[0][0] = grid[0][0];
  dp[1][0] = grid[1][0];
  for (long long int i = 1; i < m; i++) {
    dp[0][i] = grid[0][i] + dp[0][i - 1];
    dp[1][i] = dp[1][i - 1] + grid[1][i];
  }
  long long int ans = INT32_MAX;
  for (long long int i = 0; i < m; i++) {
    long long int x1 = dp[0][m - 1] - dp[0][i];
    long long int x2 = dp[1][i] - grid[1][i];
    ans = min(ans, max(x1, x2));
  }
  cout << ans << "\n";
  ;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
