#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    int b;
    cin >> b;
    a[i] = a[i + b] - b;
    a[i] = max(0, min(i, a[i]));
  }
  vector<int> dp(n + 1, -1);
  dp[n] = 0;
  for (int i = n, j = n; i > 0; --i) {
    if (~dp[i]) {
      if (j >= i) j = i - 1;
      for (; j >= 0 && j >= i - a[i]; --j) {
        dp[j] = dp[i] + 1;
      }
    }
  }
  if (~dp[0]) {
    vector<int> trc;
    for (int i = 1, cur = 0; i <= n; ++i) {
      if (~dp[i] && i - a[i] <= cur && dp[i] + 1 == dp[cur]) {
        trc.push_back(cur);
        cur = i;
      }
    }
    assert((int)trc.size() == dp[0]);
    cout << dp[0] << '\n';
    reverse(trc.begin(), trc.end());
    for (int i : trc) cout << i << ' ';
  } else {
    cout << -1;
  }
  return 0;
}
