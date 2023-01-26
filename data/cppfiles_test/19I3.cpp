#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int& e : a) cin >> e;
    int c = 2005;
    auto idk = [&](int start) {
      int ans = 1e9;
      vector<vector<int>> dp(2, vector<int>(c, 1e9));
      dp[0][start] = start;
      for (int e : a) {
        dp[1] = vector<int>(c, 1e9);
        for (int i = 0; i < c; i++) {
          if (i >= e) dp[1][i] = min(dp[1][i], max(dp[0][i - e], i));
          if (i + e < c) dp[1][i] = min(dp[1][i], max(dp[0][i + e], i));
        }
        swap(dp[0], dp[1]);
      }
      for (int i = 0; i < c; i++) ans = min(ans, dp[0][i]);
      return ans;
    };
    int l = 0, r = 1000;
    while (r - l > 2) {
      int duh = (r - l) / 3;
      int m1 = l + duh;
      int m2 = l + 2 * duh;
      if (idk(m1) < idk(m2))
        r = m2;
      else
        l = m1;
    }
    cout << min({idk(l), idk(l + 1), idk(l + 2)}) << '\n';
  }
}
