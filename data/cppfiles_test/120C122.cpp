#include <bits/stdc++.h>
using namespace std;
vector<long long> dx = {1, -1, 0, 0};
vector<long long> dy = {0, 0, -1, 1};
const long long N = 2e5 + 5;
vector<vector<long long>> dp(20, vector<long long>(2e5 + 1, 0));
void solve() {
  long long l, r;
  cin >> l >> r;
  long long mx = 0;
  for (long long i = 0; i < 20; i++) {
    mx = max(dp[i][r] - dp[i][l - 1], mx);
  }
  long long ans = r - l + 1 - mx;
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i < 2e5 + 1; i++) {
    long long j = 0;
    long long cur = i;
    while (cur) {
      if (cur & 1) {
        dp[j][i]++;
      }
      j++;
      cur = cur >> 1;
    }
  }
  for (long long i = 0; i < 20; i++) {
    for (long long j = 1; j < 2e5 + 1; j++) {
      dp[i][j] += dp[i][j - 1];
    }
  }
  while (t--) {
    solve();
  }
  return 0;
}
