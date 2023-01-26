#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
const int M = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<long long>> dp(n + 5, vector<long long>(3, 0));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0, p = 0;
  for (int i = 0; i < n; i++) {
    long long s = dp[a[i]][1] + 1;
    if (!a[i]) {
      ans += s;
      ans %= M;
      dp[a[i]][1] += s;
      dp[a[i]][1] %= M;
    } else {
      dp[a[i]][1] += dp[a[i] - 1][1];
      dp[a[i]][1] %= M;
      ans += dp[a[i]][1];
      ans %= M;
      dp[a[i]][1] += s - 1;
      dp[a[i]][1] %= M;
    }
    if (a[i] == 1) {
      s = p;
      p += 1;
      ans += p;
      ans %= M;
      p += s;
      p %= M;
    }
    if (a[i] - 2 >= 0) {
      s = dp[a[i]][2];
      dp[a[i]][2] += dp[a[i] - 2][1] + dp[a[i] - 2][0];
      dp[a[i]][2] %= M;
      ans += dp[a[i]][2];
      ans %= M;
      dp[a[i]][2] += s;
      dp[a[i]][2] %= M;
    }
    s = dp[a[i]][0];
    dp[a[i]][0] += dp[a[i] + 2][2];
    dp[a[i]][0] %= M;
    ans += dp[a[i]][0];
    ans %= M;
    dp[a[i]][0] += s;
    dp[a[i]][0] %= M;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
