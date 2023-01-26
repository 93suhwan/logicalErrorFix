#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const bool debugFlag = true;
const lint linf = 1e18 + 7;
const lint inf = 1e9 + 7;
const int MOD = 1000000007;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) a[i] -= i + 1;
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    auto nxt = dp;
    for (int j = 0; j < n; ++j) nxt[j] = max(nxt[j], dp[j] + (int)(a[i] == -j));
    for (int j = 1; j <= n; ++j) nxt[j] = max(nxt[j], dp[j - 1]);
    swap(nxt, dp);
  }
  for (int i = 0; i < n; ++i) {
    if (dp[i] >= k) {
      cout << i << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
