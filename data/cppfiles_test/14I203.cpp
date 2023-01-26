#include <bits/stdc++.h>
using namespace std;
void trace_() { cerr << "\n"; }
template <typename T1, typename... T2>
void trace_(T1 t1, T2... t2) {
  cerr << ' ' << t1;
  trace_(t2...);
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), d(n);
  for (auto &i : a) cin >> i;
  for (int i = 0; i < n; i++) d[i] = i + 1 - a[i];
  vector<vector<int>> dp(n + 5, vector<int>(n + 5));
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = dp[i][0];
    for (int j = 1; j <= i; j++) dp[i + 1][j] = dp[i][j - 1];
    if (d[i] < 0 || d[i] > i) continue;
    dp[i + 1][d[i]] = max(dp[i + 1][d[i]], dp[i][d[i]] + 1);
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      if (dp[i][j] >= k) ans = min(ans, j);
    }
  if (ans == 1e9) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) solve();
}
