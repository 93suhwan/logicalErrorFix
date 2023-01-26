#include <bits/stdc++.h>
using namespace std;
int n, k, a[2005], dp[2005][2005], l;
int DP(int p, int m) {
  if (p == n + 1) return 0;
  if (dp[p][m] != -1) return dp[p][m];
  if (m == l) {
    if (p - m == a[p])
      return dp[p][m] = 1 + DP(p + 1, m);
    else
      return dp[p][m] = DP(p + 1, m);
  } else {
    if (p - m == a[p])
      return dp[p][m] = max(1 + DP(p + 1, m), DP(p + 1, m + 1));
    else
      return dp[p][m] = max(DP(p + 1, m), DP(p + 1, m + 1));
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int lo = 0, hi = n, mid, ans = -1;
  while (lo <= hi) {
    memset(dp, -1, sizeof dp);
    mid = (lo + hi) / 2;
    l = mid;
    if (DP(1, 0) >= k) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(chrono::steady_clock::now().time_since_epoch().count());
  int T = 1, cs = 0;
  cin >> T;
  while (T--) {
    solve();
  }
}
