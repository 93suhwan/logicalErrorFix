#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long nax = 3000 + 10, mod = 1e9 + 7, inf = 1e18;
long long dp[2][nax], n;
void solve() {
  memset(dp, 1, sizeof(dp));
  dp[0][0] = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x, v = i % 2;
    cin >> x;
    memset(dp[!v], 1, sizeof(dp[!v]));
    for (long long j = 0; j < 3002; j++) {
      {
        long long nxt = dp[v][j] + max(0LL, x - j);
        long long nxt1 = max(0LL, j - x);
        if (nxt < 3002 and nxt1 < 3002) dp[!v][nxt1] = min(dp[!v][nxt1], nxt);
      }
      {
        long long nxt = max(dp[v][j], j + x);
        long long nxt1 = j + x;
        if (nxt < 3002 and nxt1 < 3002) dp[!v][nxt1] = min(dp[!v][nxt1], nxt);
      }
    }
  }
  long long res = 2e9;
  for (long long i = 0; i < 3002; i++) res = min(res, dp[(n % 2)][i]);
  cout << res;
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  for (long long i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
