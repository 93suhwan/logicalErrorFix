#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> dp(2, vector<long long>(n));
  for (int i = 0; i < n; i++) cin >> dp[0][i];
  for (int i = 0; i < n; i++) cin >> dp[1][i];
  vector<vector<long long>> Dp(2, vector<long long>(n + 1, 0));
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j < n; j++) Dp[i][j + 1] = Dp[i][j] + dp[i][j];
  long long ans = 1e9;
  for (int i = 0; i < n; i++)
    ans = min(ans, max(Dp[1][i], Dp[0][n] - Dp[0][i + 1]));
  cout << (ans) << "\n";
  ;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
