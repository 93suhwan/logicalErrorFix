#include <bits/stdc++.h>
using namespace std;
const int maxn = 8192;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> p(maxn);
  for (int i = 0; i < n; ++i) cin >> a[i], p[a[i]].push_back(i);
  vector<int> dp(maxn, n);
  dp[0] = -1;
  for (int i = 1; i <= 5000; ++i) {
    vector<int> nw = dp;
    for (int j = 0; j < maxn; ++j)
      if (dp[j] <= n) {
        auto nx = lower_bound(p[i].begin(), p[i].end(), dp[j]);
        if (nx != p[i].end()) {
          nw[i ^ j] = min(nw[i ^ j], *nx);
        }
      }
    swap(nw, dp);
  }
  vector<int> ans;
  for (int i = 0; i < maxn; ++i)
    if (dp[i] < n) ans.push_back(i);
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << " ";
  return 0;
}
